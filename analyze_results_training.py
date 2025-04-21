import os
import csv
import re
import pandas as pd

output_dir = "output_csvs"

os.makedirs(output_dir, exist_ok=True)
os.makedirs(output_dir + '/validity', exist_ok=True)
os.makedirs(output_dir + '/validity/disagreements', exist_ok=True)
os.makedirs(output_dir + '/errors', exist_ok=True)

pd.set_option('display.max_rows', None)
pd.set_option('display.max_columns', None)
df = pd.read_csv("output_csvs/output_results.csv")


timeout = df[(df["CBMC_Verified"] == "timeout")]
over_context = df[(df["GPT_Verified"] == "long")]
cbmc_verified = df[(df["CBMC_Verified"] == "verified")]
gpt_verified = df[(df["GPT_Verified"] == "verified")]
df = df[(df["CBMC_Verified"] != "timeout") & (df["GPT_Verified"] != "long")]
disagreements = df[
    (df["CBMC_Verified"] != df["GPT_Verified"])
]
disagreements_unwind = df[
    (df["CBMC_Verified_Unwind"] != df["GPT_Verified"])
]

disagreements_gpt_pos = disagreements[disagreements['GPT_Verified'] == 'failed']

# disagreements in validity 
num_disagreements = len(disagreements)
num_disagreements_unwind = len(disagreements_unwind)
print("Total files: " + str(len(df)))
print("CBMC timeouts: " + str(len(timeout)) + ", " + str(len(timeout)/len(df)*100) + "% of all files")
print("GPT over context: " + str(len(over_context)) + ", " + str(len(over_context)/len(df)*100) + "% of all files")
print()
print("CBMC number verified: " + str(len(cbmc_verified)) + ", " + str(len(cbmc_verified)/len(df)*100) + "% of all files")
print("GPT number verified: " + str(len(gpt_verified)) + ", " + str(len(gpt_verified)/len(df)*100) + "% of all files")
print("GPT false positive: " + str(len(disagreements_gpt_pos)) + ", " + str(len(disagreements_gpt_pos)/len(disagreements)*100) + "% of all disagreements")

# convert all counts to 1
df["CBMC_Arithmetic_Overflow"] = (df["CBMC_Arithmetic_Overflow"] > 0).astype(int)
df["CBMC_Buffer_Overflow"] = (df["CBMC_Buffer_Overflow"] > 0).astype(int)
df["CBMC_Dereference_Failure"] = (df["CBMC_Dereference_Failure"] > 0).astype(int)
df["CBMC_Pointer_Relation"] = (df["CBMC_Pointer_Relation"] > 0).astype(int)

# error statistics for validity disagreements
print()
print("DISAGREEMENT ERROR STATS")

disagreement_errors = disagreements[((disagreements["CBMC_Arithmetic_Overflow"] != disagreements["GPT_Arithmetic_Overflow"]) | 
                          (disagreements["CBMC_Buffer_Overflow"] != disagreements["GPT_Buffer_Overflow"]) |
                          (disagreements["CBMC_Dereference_Failure"] != disagreements["GPT_Dereference_Failure"]) |
                          (disagreements["CBMC_Pointer_Relation"] != disagreements["GPT_Pointer_Relation"]))]

disagreement_ao = disagreement_errors[disagreement_errors["CBMC_Arithmetic_Overflow"] != disagreement_errors["GPT_Arithmetic_Overflow"]]
ao_gpt = disagreement_ao[disagreement_ao["CBMC_Arithmetic_Overflow"] == 0]
ao_gpt.to_csv(output_dir + '/validity/disagreements/ao_gpt.csv', index=False)

disagreement_bo = disagreement_errors[disagreement_errors["CBMC_Buffer_Overflow"] != disagreement_errors["GPT_Buffer_Overflow"]]
bo_gpt = disagreement_bo[disagreement_bo["CBMC_Buffer_Overflow"] == 0]
bo_gpt.to_csv(output_dir + '/validity/disagreements/bo_gpt.csv', index=False)

disagreement_df = disagreement_errors[disagreement_errors["CBMC_Dereference_Failure"] != disagreement_errors["GPT_Dereference_Failure"]]
df_gpt = disagreement_df[disagreement_df["CBMC_Dereference_Failure"] == 0]
df_gpt.to_csv(output_dir + '/validity/disagreements/df_gpt.csv', index=False)

disagreement_pr = disagreement_errors[disagreement_errors["CBMC_Pointer_Relation"] != disagreement_errors["GPT_Pointer_Relation"]]
pr_gpt = disagreement_pr[disagreement_pr["CBMC_Pointer_Relation"] == 0]
pr_gpt.to_csv(output_dir + '/validity/disagreements/pr_gpt.csv', index=False)

combined = pd.concat([disagreement_ao.assign(source='df1'), 
                      disagreement_bo.assign(source='df2'), 
                      disagreement_df.assign(source='df3'), 
                      disagreement_pr.assign(source='df4')])
row_counts = combined.drop(columns=['source']).value_counts().reset_index(name='count')
one_disagreement = row_counts[row_counts['count'] == 1].drop(columns=['count'])
two_disagreements = row_counts[row_counts['count'] == 2].drop(columns=['count'])
three_disagreements = row_counts[row_counts['count'] == 3].drop(columns=['count'])
four_disagreements = row_counts[row_counts['count'] == 4].drop(columns=['count'])

disagreement_ao.to_csv(output_dir + '/validity/disagreements/error_ao.csv', index=False)
disagreement_bo.to_csv(output_dir + '/validity/disagreements/error_bo.csv', index=False)
disagreement_df.to_csv(output_dir + '/validity/disagreements/error_df.csv', index=False)
disagreement_pr.to_csv(output_dir + '/validity/disagreements/error_pr.csv', index=False)

# output error stats for validity disagreements
print("Total: " + str(len(disagreement_errors)) + ", " + str(len(disagreement_errors)/len(df)*100) + "% of all cases")
print("Number of error disagreements: ")
print("1: " + str(len(one_disagreement)) + ", " + str(len(one_disagreement)/len(disagreement_errors)*100) + "% of all error disagreements")
print("2: " + str(len(two_disagreements)) + ", " + str(len(two_disagreements)/len(disagreement_errors)*100) + "% of all error disagreements")
print("3: " + str(len(three_disagreements)) + ", " + str(len(three_disagreements)/len(disagreement_errors)*100) + "% of all error disagreements")
print("4: " + str(len(four_disagreements)) + ", " + str(len(four_disagreements)/len(disagreement_errors)*100) + "% of all error disagreements")
print()
print("Arithmetic Overflow: " + str(len(disagreement_ao)) + ", " + str(len(ao_gpt)/len(disagreement_ao)*100) + "% gpt positive")
print("Buffer Overflow: " + str(len(disagreement_bo)) + ", " + str(len(bo_gpt)/len(disagreement_bo)*100) + "% gpt positive")
print("Dereference Failure: " + str(len(disagreement_df)) + ", " + str(len(df_gpt)/len(disagreement_df)*100) + "% gpt positive")
print("Pointer Relation: " + str(len(disagreement_pr)) + ", " + str(len(pr_gpt)/len(disagreement_pr)*100) + "% gpt positive")
print("In total, " + str((len(ao_gpt)+len(bo_gpt)+len(df_gpt)+len(pr_gpt))/(len(disagreement_ao)+len(disagreement_bo)+len(disagreement_df)+len(disagreement_pr))*100) + "% gpt positive")


df["CBMC_Arithmetic_Overflow"] = (df["CBMC_Arithmetic_Overflow"] > 0).astype(int)
df["CBMC_Buffer_Overflow"] = (df["CBMC_Buffer_Overflow"] > 0).astype(int)
df["CBMC_Dereference_Failure"] = (df["CBMC_Dereference_Failure"] > 0).astype(int)
df["CBMC_Pointer_Relation"] = (df["CBMC_Pointer_Relation"] > 0).astype(int)
disagreement_errors = df[((df["CBMC_Arithmetic_Overflow"] != df["GPT_Arithmetic_Overflow"]) | 
                          (df["CBMC_Buffer_Overflow"] != df["GPT_Buffer_Overflow"]) |
                          (df["CBMC_Dereference_Failure"] != df["GPT_Dereference_Failure"]) |
                          (df["CBMC_Pointer_Relation"] != df["GPT_Pointer_Relation"]))]
disagreement_errors.to_csv(output_dir + '/errors/all.csv', index=False)
disagreement_ao = disagreement_errors[disagreement_errors["CBMC_Arithmetic_Overflow"] != disagreement_errors["GPT_Arithmetic_Overflow"]]
# gpt 1 but cbmc 0
ao_gpt = disagreement_ao[disagreement_ao["CBMC_Arithmetic_Overflow"] == 0]
ao_gpt.to_csv(output_dir + '/errors/ao_gpt.csv', index=False)
disagreement_bo = disagreement_errors[disagreement_errors["CBMC_Buffer_Overflow"] != disagreement_errors["GPT_Buffer_Overflow"]]
bo_gpt = disagreement_bo[disagreement_bo["CBMC_Buffer_Overflow"] == 0]
bo_gpt.to_csv(output_dir + '/errors/bo_gpt.csv', index=False)
disagreement_df = disagreement_errors[disagreement_errors["CBMC_Dereference_Failure"] != disagreement_errors["GPT_Dereference_Failure"]]
df_gpt = disagreement_df[disagreement_df["CBMC_Dereference_Failure"] == 0]
df_gpt.to_csv(output_dir + '/errors/df_gpt.csv', index=False)
disagreement_pr = disagreement_errors[disagreement_errors["CBMC_Pointer_Relation"] != disagreement_errors["GPT_Pointer_Relation"]]
pr_gpt = disagreement_pr[disagreement_pr["CBMC_Pointer_Relation"] == 0]
pr_gpt.to_csv(output_dir + '/errors/pr_gpt.csv', index=False)
combined = pd.concat([disagreement_ao.assign(source='df1'), 
                      disagreement_bo.assign(source='df2'), 
                      disagreement_df.assign(source='df3'), 
                      disagreement_pr.assign(source='df4')])
row_counts = combined.drop(columns=['source']).value_counts().reset_index(name='count')
one_disagreement = row_counts[row_counts['count'] == 1].drop(columns=['count'])
two_disagreements = row_counts[row_counts['count'] == 2].drop(columns=['count'])
three_disagreements = row_counts[row_counts['count'] == 3].drop(columns=['count'])
four_disagreements = row_counts[row_counts['count'] == 4].drop(columns=['count'])
disagreement_ao.to_csv(output_dir + '/errors/error_ao.csv', index=False)
disagreement_bo.to_csv(output_dir + '/errors/error_bo.csv', index=False)
disagreement_df.to_csv(output_dir + '/errors/error_df.csv', index=False)
disagreement_pr.to_csv(output_dir + '/errors/error_pr.csv', index=False)

print()
print("OVERALL ERROR STATS")
print("Number of error disagreements: ")
print("Total: " + str(len(disagreement_errors)) + ", " + str(len(disagreement_errors)/len(df)*100) + "% of all cases")
print("1: " + str(len(one_disagreement)) + ", " + str(len(one_disagreement)/len(disagreement_errors)*100) + "% of all error disagreements")
print("2: " + str(len(two_disagreements)) + ", " + str(len(two_disagreements)/len(disagreement_errors)*100) + "% of all error disagreements")
print("3: " + str(len(three_disagreements)) + ", " + str(len(three_disagreements)/len(disagreement_errors)*100) + "% of all error disagreements")
print("4: " + str(len(four_disagreements)) + ", " + str(len(four_disagreements)/len(disagreement_errors)*100) + "% of all error disagreements")
print()
print("Arithmetic Overflow: " + str(len(disagreement_ao)) + ", " + str(len(ao_gpt)/len(disagreement_ao)*100) + "% gpt positive")
print("Buffer Overflow: " + str(len(disagreement_bo)) + ", " + str(len(bo_gpt)/len(disagreement_bo)*100) + "% gpt positive")
print("Dereference Failure: " + str(len(disagreement_df)) + ", " + str(len(df_gpt)/len(disagreement_df)*100) + "% gpt positive")
print("Pointer Relation: " + str(len(disagreement_pr)) + ", " + str(len(pr_gpt)/len(disagreement_pr)*100) + "% gpt positive")
print("In total, " + str((len(ao_gpt)+len(bo_gpt)+len(df_gpt)+len(pr_gpt))/(len(disagreement_ao)+len(disagreement_bo)+len(disagreement_df)+len(disagreement_pr))*100) + "% gpt positive")

print()
print("Number of disagreements when unwind assertion is not counted: " + str(num_disagreements_unwind))
percent_disagreements_unwind = num_disagreements_unwind/len(df) * 100
print("Percentage disagreements when unwind assertion is not counted: " + str(percent_disagreements_unwind) + "%")
disagreements_unwind.to_csv(output_dir + '/disagreements_unwind_cprover.csv', index=False)


print()
avg_time_gpt = df["GPT_Execution_Time"].sum()/len(df)
print("Average time with gpt: " + str(avg_time_gpt))
avg_time_cbmc = df["CBMC_Execution_Time"].sum()/len(df)
print("Average time with cbmc: " + str(avg_time_cbmc))

# what else do i want to know?
# where errors predicted actually differ
# best way to do this?
# - find which percentage agreed upon the error (types) when agreeing upon verification
