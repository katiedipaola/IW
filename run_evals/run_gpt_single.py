# run gpt on single file - no dependencies

from openai import OpenAI
import os
import time

prompt = "Check this C program for the following four errors: 1. Buffer Overflow. 2. Dereference Failure. This means dereferencing a null/invalid/dangling pointer. 3. Pointer Relation. This means pointers not within valid allocated memory or pointer arithmetic that leads to undefined behavior. 4. Arithmetic Overflow. If you find such an error, state the error type, exactly where the error occurred, and provide an example input that results in the error. Do not output any more information than that. Do not output the error type unless you found an example of the error. For example, do not put the words 'Arithmetic Overflow' in your response unless you find an arithmetic overflow error. Be concise. If you do not find any errors, simply output 'Program Verified' and nothing else. Follow these directions exactly.\n"
file_path = "/"
output_dir = ""
os.makedirs(output_dir, exist_ok=True)
file_name = ""
api_key = ""

with open(file_path+file_name, "r") as file:
    code = file.read()

    message = prompt + code

    client = OpenAI(api_key=api_key)
    completion = client.chat.completions.create(
        model="gpt-4o",
        messages=[
            {"role": "system", "content": "You are a C verification program that finds bugs in C code."},
            {
                "role": "user",
                "content": message
            }
        ]
    )

    write_path = os.path.join(output_dir, f"{file_name}.gpt_out.txt")
    with open(write_path, "w") as output_file:
        print(completion.choices[0].message.content, file=output_file)