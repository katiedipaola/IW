import os
import csv
import re
import pandas as pd

# Directories containing the files
# cbmc_dir = 'cbmc_results_cprover'
# gpt_dir = 'gpt_results_cprover2'
cbmc_dir = 'cbmc_results'
gpt_dir = 'gpt_results'

# Define field names
fieldnames = ['File_Number', 'CBMC_Verified', 'CBMC_Arithmetic_Overflow', 'CBMC_Buffer_Overflow',
              'CBMC_Dereference_Failure', 'CBMC_Pointer_Relation', 'CBMC_Unwinding_Assertion', 'CBMC_Verified_Unwind',
              'GPT_Verified', 'GPT_Arithmetic_Overflow', 'GPT_Buffer_Overflow', 'GPT_Dereference_Failure',
              'GPT_Pointer_Relation', 'CBMC_Execution_Time', 'GPT_Execution_Time']

# List to store data before creating DataFrame
data = []

# Iterate over all files in the CBMC results directory
for filename in os.listdir(cbmc_dir):
    file_name = filename[:-15]

    cbmc_arithmetic_overflow = 0
    cbmc_buffer_overflow = 0
    cbmc_dereference_failure = 0
    cbmc_pointer_relation = 0
    cbmc_unwinding_assertion = 0
    cbmc_exec_time = None

    # Read CBMC result
    with open(os.path.join(cbmc_dir, filename), 'r') as f:
        failure_lines = []
        for line in f:
            line_s = line.strip()
            if line_s.endswith("FAILURE"):
                failure_lines.append(line_s)
                if "arithmetic overflow" in line_s:
                    cbmc_arithmetic_overflow += 1
                elif "array" in line_s:
                    cbmc_buffer_overflow += 1
                elif "dereference failure" in line_s:
                    cbmc_dereference_failure += 1
                elif "pointer relation" in line_s:
                    cbmc_pointer_relation += 1
                elif "unwinding assertion" in line_s:
                    cbmc_unwinding_assertion += 1
            elif line_s.startswith("real"):
                m = line_s.index("m")
                mins = line_s[m - 1]
                secs = line_s[m + 1:-1]
                cbmc_exec_time = float(mins) * 60 + float(secs)
            elif "VERIFICATION SUCCESSFUL" in line_s:
                cbmc_result = 'verified'
            elif "VERIFICATION FAILED" in line_s:
                cbmc_result = "failed"
            elif "Timed Out" in line_s:
                cbmc_result = "timeout"
            elif line_s.startswith("Execution Time"):
                end = line_s.index("seconds")
                cbmc_exec_time = line_s[16:end-1]

        if cbmc_result == 'failed' and cbmc_arithmetic_overflow == 0 and cbmc_buffer_overflow == 0 and cbmc_dereference_failure == 0 and cbmc_pointer_relation == 0 and cbmc_unwinding_assertion > 0:
            cbmc_verified_unwind = 'verified'
        else:
            cbmc_verified_unwind = cbmc_result

    # Read GPT result
    gpt_filename = file_name + '.c.gpt_out.txt'
    with open(os.path.join(gpt_dir, gpt_filename), 'r') as f:
        content = f.read().lower()
        gpt_result = 'verified' if 'program verified' in content else 'long' if 'over maximum context' in content else 'failed'
        if gpt_result != 'verified':
            gpt_dereference_failure = 1 if 'dereference' in content else 0
            gpt_pointer_relation = 1 if 'pointer relation' in content else 0
            gpt_buffer_overflow = 1 if 'buffer overflow' in content else 0
            gpt_arithmetic_overflow = 1 if 'arithmetic overflow' in content else 0
        else:
            gpt_dereference_failure = 0
            gpt_pointer_relation = 0
            gpt_buffer_overflow = 0
            gpt_arithmetic_overflow = 0

        match = re.search(r'execution time: ([\d\.]+) seconds', content)
        gpt_exec_time = float(match.group(1)) if match else None

    # Append data to list
    data.append({
        'File_Number': file_name,
        'CBMC_Verified': cbmc_result,
        'CBMC_Arithmetic_Overflow': cbmc_arithmetic_overflow,
        'CBMC_Buffer_Overflow': cbmc_buffer_overflow,
        'CBMC_Dereference_Failure': cbmc_dereference_failure,
        'CBMC_Pointer_Relation': cbmc_pointer_relation,
        'CBMC_Unwinding_Assertion': cbmc_unwinding_assertion,
        'CBMC_Verified_Unwind': cbmc_verified_unwind,
        'GPT_Verified': gpt_result,
        'GPT_Arithmetic_Overflow': gpt_arithmetic_overflow,
        'GPT_Buffer_Overflow': gpt_buffer_overflow,
        'GPT_Dereference_Failure': gpt_dereference_failure,
        'GPT_Pointer_Relation': gpt_pointer_relation,
        'CBMC_Execution_Time': cbmc_exec_time,
        'GPT_Execution_Time': gpt_exec_time
    })

# Create a DataFrame and save it as CSV
df = pd.DataFrame(data)
df.to_csv('output_results.csv', index=False)

print('CSV file has been written successfully.')
