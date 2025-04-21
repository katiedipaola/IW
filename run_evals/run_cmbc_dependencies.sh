#!/bin/bash

# run cmbc on all files in buggy_dir - with dependencies

# Directory containing buggy .c files
buggy_dir="buggy_code_cprover"
output_dir="cbmc_results_cprover"
mkdir -p "$output_dir"

stubs_path="$buggy_dir/stubs.c"

# CBMC command options
cbmc_options="--unwind 10 --trace"

# Timeout duration in seconds (10 minutes)
timeout_duration=$((10 * 60))

# Iterate over all directories in buggy_code_cprover
for folder in "$buggy_dir"/*; do
    if [[ -d "$folder" ]]; then
        folder_name=$(basename "$folder")
        for file in "$folder"/*.c; do
            if [[ -f "$file" && "$(basename "$file")" != "dependency.c" ]]; then
                filename=$(basename "$file")
                print_filename="${folder_name}.${filename}"
                output_path="$output_dir/${print_filename}.cbmc_out.txt"

                if [[ ! -f "$output_path" ]]; then
                    echo "Starting CBMC analysis for $print_filename"

                    # Check if dependency.c exists
                    dependency_path="$folder/dependency.c"
                    if [[ ! -f "$dependency_path" ]]; then
                        dependency_path=""
                    fi

                    # Build CBMC command
                    if [[ -n "$dependency_path" ]]; then
                        cmd=("cbmc" "$file" "$stubs_path" "$dependency_path" $cbmc_options)
                    else
                        cmd=("cbmc" "$file" "$stubs_path" $cbmc_options)
                    fi

                    echo "Running command: ${cmd[*]}"

                    # Run CBMC with timeout and measure execution time
                    {
                        # Use time to capture execution time
                        { time timeout "$timeout_duration" "${cmd[@]}" >"$output_path" 2>&1; } 2>> "$output_path" | grep real | awk '{print "Execution Time: " $2}' >> "$output_path"
                        echo "CBMC analysis completed for $print_filename, results saved to $output_path"
                    } || {
                        echo "CBMC analysis timed out or failed for $print_filename, result saved to $output_path"
                        echo "Timed Out" > "$output_path"
                    }
                fi
            fi
        done
    fi
done
