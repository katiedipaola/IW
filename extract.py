import gzip
import json
import os


file_path = "c_train0.jsonl.gz"

output_dir1 = "buggy_code"
os.makedirs(output_dir1, exist_ok=True)
output_dir2 = "fixed_code"
os.makedirs(output_dir2, exist_ok=True)

with gzip.open(file_path, "rt", encoding="utf-8") as f:
    for i, line in enumerate(f):
        entry = json.loads(line)
        problem_id = entry["problem_id"]
        buggy_path = os.path.join(output_dir1, f"{problem_id}_buggy.c")
        fixed_path = os.path.join(output_dir2, f"{problem_id}_fixed.c")

        with open(buggy_path, "w") as buggy_file:
            buggy_file.write(entry["buggy_code"])

        with open(fixed_path, "w") as fixed_file:
            fixed_file.write(entry["fixed_code"])

print(f"Extracted code files saved")