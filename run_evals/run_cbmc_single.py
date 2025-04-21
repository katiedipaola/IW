# run cbmc on single file - no dependencies

import os
import subprocess
import time

# Directory containing buggy .c files
buggy_dir = "buggy_code"
output_dir = "cbmc_results"
os.makedirs(output_dir, exist_ok=True)

# CBMC command options
cbmc_options = "--depth 200 --unwind 10 --trace"

# Timeout duration in seconds (10 minutes)
timeout_duration = 10 * 60  
filename = "p00001_buggy.c"

file_path = os.path.join(buggy_dir, filename)
output_path = os.path.join(output_dir, f"{filename}.cbmc_out.txt")

print(f"Starting CBMC analysis for {filename}")
start_time = time.time()

try:
    result = subprocess.run(
        ["cbmc", file_path] + cbmc_options.split(),
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True,
        timeout=timeout_duration  # Set timeout
    )
    end_time = time.time()
    duration = end_time - start_time
    
    # Save output
    with open(output_path, "w") as f:
        f.write(result.stdout)
        f.write("\nErrors:\n")
        f.write(result.stderr)
        f.write(f"\nExecution Time: {duration:.2f} seconds\n")
    
    print(f"CBMC analysis completed for {filename}, results saved to {output_path}")

except subprocess.TimeoutExpired:
    with open(output_path, "w") as f:
        f.write("Timed Out\n")
    print(f"CBMC analysis timed out for {filename}, result saved to {output_path}")

except Exception as e:
    print(f"Error running CBMC on {filename}: {e}")