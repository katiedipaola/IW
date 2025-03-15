from openai import OpenAI
import os
import time

prompt = "Check this c program for buffer overflow, memory leaks, and arithmetic overflow. If you find such an error, state the error type, exactly where the error occurred including line numbers, and provide an example input that results in the error. Do not output any more information that that. Be concise. If you do not find any errors, simply output 'Program Verified'.\n"
file_path = "buggy_code/"
output_dir = "gpt_results"
os.makedirs(output_dir, exist_ok=True)

file_name = "p03524_buggy.c"

with open(file_path+file_name, "r") as file:
    code = file.read()

    message = prompt + code

    client = OpenAI(api_key="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")
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

    write_path = os.path.join(output_dir, f"{file_name}.gpt_out.txt")
    with open(write_path, "w") as output_file:
        print(completion.choices[0].message.content, file=output_file)
    # print(completion.choices[0].message)



# # Directory containing buggy .c files
# buggy_dir = "buggy_code"
# output_dir = "gpt_results"
# os.makedirs(output_dir, exist_ok=True)

# # GPT prompt
# prompt = "Check this c program for buffer overflow, memory leaks, and arithmetic overflow. If you find such an error, state the error type, exactly where the error occurred, and provide an example input that results in the error. Do not output any more information that that. Be concise. If you do not find any errors, simply output 'Program Verified'.\n"

# # Iterate over all .c files in buggy_code
# for filename in os.listdir(buggy_dir):
#     if filename.endswith(".c"):
#         file_path = os.path.join(buggy_dir, filename)
#         output_path = os.path.join(output_dir, f"{filename}.gpt_out.txt")
        
#         # Run gpt
#         with open(file_path+file_name, "r") as file:
#             code = file.read()

#             message = prompt + code

#             client = OpenAI(api_key="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")
#             start_time = time.time()
#             completion = client.chat.completions.create(
#                 model="gpt-4o-mini",
#                 messages=[
#                     {"role": "system", "content": "You are a C verification program that finds bugs in C code."},
#                     {
#                         "role": "user",
#                         "content": message
#                     }
#                 ]
#             )
#             end_time = time.time()
#             duration = end_time - start_time

#             write_path = os.path.join(output_dir, f"{file_name}.gpt_out.txt")
#             with open(write_path, "w") as output_file:
#                 print(completion.choices[0].message.content, file=output_file)
#                 print(f"\nExecution Time: {duration:.2f} seconds\n", file=output_file)
#         print(f"GPT analysis completed for {filename}, results saved to {write_path}")