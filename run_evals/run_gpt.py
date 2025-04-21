# run gpt on all files in buggy_dir - no dependencies

from openai import OpenAI
import os
import time


# Directory containing buggy .c files
buggy_dir = "buggy_code"
output_dir = "gpt_results"
os.makedirs(output_dir, exist_ok=True)

# GPT prompt
prompt = "Check this C program for the following four errors: 1. Buffer Overflow. 2. Dereference Failure. This means dereferencing a null/invalid/dangling pointer. 3. Pointer Relation. This means pointers not within valid allocated memory or pointer arithmetic that leads to undefined behavior. 4. Arithmetic Overflow. If you find an error, state the error type, exactly where the error occurred, and provide an example input that results in the error. Do not output any more information than that. Do not output the error type unless you found an example of the error. For example, do not put the words 'Arithmetic Overflow' in your response unless you find an arithmetic overflow error. Be concise. If you do not find any errors, simply output 'Program Verified' and nothing else. Follow these directions exactly.\n"

# Iterate over all .c files in buggy_code
for filename in os.listdir(buggy_dir):
    if filename.endswith(".c"):
        file_path = os.path.join(buggy_dir, filename)
        output_path = os.path.join(output_dir, f"{filename}.gpt_out.txt")

        if not os.path.exists(output_path):
            print(f"Starting gpt for {filename}")
        
            # Run gpt
            with open(file_path, "r") as file:
                code = file.read()

                message = prompt + code

                client = OpenAI(api_key="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")
                start_time = time.time()
                completion = client.chat.completions.create(
                    model="gpt-4o-mini",
                    messages=[
                        {"role": "system", "content": "You are a C verification program that finds bugs in C code."},
                        {
                            "role": "user",
                            "content": message
                        }
                    ]
                )
                end_time = time.time()
                duration = end_time - start_time

                write_path = os.path.join(output_dir, f"{filename}.gpt_out.txt")
                with open(write_path, "w") as output_file:
                    print(completion.choices[0].message.content, file=output_file)
                    print(f"\nExecution Time: {duration:.2f} seconds\n", file=output_file)
            print(f"GPT analysis completed for {filename}, results saved to {write_path}")