# run gpt on single file - with dependencies

from openai import OpenAI
import os
import time


# Directory containing buggy .c files
buggy_dir = "buggy_code_cprover"
output_dir = "gpt_results_cprover2"
os.makedirs(output_dir, exist_ok=True)
folder_to_run = "NetBSD-libc"
file_to_run = "anyMeta_ptr_bad.c"

# GPT prompt
prompt = "Check the Main file C program and any functions it calls from its included files for the following four errors: 1. Buffer Overflow. 2. Dereference Failure. This means dereferencing a null/invalid/dangling pointer. 3. Pointer Relation. This means pointers not within valid allocated memory or pointer arithmetic that leads to undefined behavior. 4. Arithmetic Overflow. If you find an error, state the error type, exactly where the error occurred, and provide an example input that results in the error. Do not output any more information than that. Do not output the error type unless you found an example of the error. For example, do not put the words 'Arithmetic Overflow' in your response unless you find an arithmetic overflow error. Do not output any errors that occur in functions in the included files not called by the Main file. You must assume that constant variables from .h files can never change. Be concise. If you do not find any errors, simply output 'Program Verified' and nothing else. Follow these directions exactly.\n"

stubs_c_path = os.path.join(buggy_dir, "stubs.c")
stubs_h_path = os.path.join(buggy_dir, "stubs.h")
base_h_path = os.path.join(buggy_dir, "base.h")
stubs_c = ""
stubs_h = ""
base_h = ""
with open(stubs_c_path, "r") as file:
    stubs_c = file.read()
with open(stubs_h_path, "r") as file:
    stubs_h = file.read()
with open(base_h_path, "r") as file:
    base_h = file.read()

# Iterate over all .c files in buggy_code
for folder in os.listdir(buggy_dir):
    if not folder.endswith(".c") and not folder.endswith(".h") and folder == folder_to_run:
        folder_path = os.path.join(buggy_dir, folder)

        # store contents of dependency files
        dependency_h_path = os.path.join(folder_path, "dependency.h")
        dependency_h = ""
        if os.path.exists(dependency_h_path):
            with open(dependency_h_path, "r") as file:
                dependency_h = file.read()
        dependency_c_path = os.path.join(folder_path, "dependency.c")
        dependency_c = ""
        if os.path.exists(dependency_c_path):
            with open(dependency_c_path, "r") as file:
                dependency_c = file.read()
        dependency2_h_path = os.path.join(folder_path, "dependency2.h")
        dependency2_h = ""
        if os.path.exists(dependency2_h_path):
            with open(dependency2_h_path, "r") as file:
                dependency2_h = file.read()
        
        for filename in os.listdir(folder_path):
            if filename.endswith(".c") and not filename == "dependency.c" and filename == file_to_run:
                file_path = os.path.join(folder_path, filename)
                output_name = folder + "." + filename + ".gpt_out2.txt"
                output_path = os.path.join(output_dir, output_name)

                if not os.path.exists(output_path):

                    # Run gpt
                    with open(file_path, "r") as file:
                        code = file.read()
                        message = prompt + "Main file:\n" + code

                        # include all dependencies in prompt
                        includes_stub = False
                        if "include \"dependency2.h\"" in code:
                            message += "\nIncluded file dependency2.h:\n" + dependency2_h + "\nIncluded file dependency.h:\n" + dependency_h + "\nstubs.h:\n" + stubs_h + "\nstubs.c:\n" + stubs_c
                        else:
                            # if uses dependency.h
                            if "include \"dependency.h\"" in code:
                                message += "\nIncluded File dependency.h:\n" + dependency_h
                                # and depdendency.c
                                if dependency_c != "":
                                    message += "\nIncluded File dependency.c:\n" + dependency_c
                                # and stubs.h/stubs.c
                                if "include \"../stubs.h\"" in dependency_h:
                                    message += "\nIncluded File stubs.h:\n" + stubs_h + "\nIncluded File stubs.c:\n" + stubs_c
                                    includes_stub = True
                            if "include \"../base.h\"" in code:
                                message += "\nIncluded File base.h:\n" + base_h
                            if "include \"../stubs.h\"" in code and not includes_stub:
                                message += "\nIncluded File stubs.h:\n" + stubs_h + "\nIncluded File stubs.c:\n" + stubs_c
                        
                        # make call to gpt
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

                        with open(output_path, "w") as output_file:
                            print(completion.choices[0].message.content, file=output_file)
                            print(f"\nExecution Time: {duration:.2f} seconds\n", file=output_file)
                            # print(message, file=output_file)
                    print(f"GPT analysis completed for {filename}, results saved to {output_path}")