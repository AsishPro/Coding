import csv
direct=input("Enter the path:")
x="\\\\"
direct=direct.split("\\")
direct=x.join(direct)
print(direct)
# with open(direct) as f:
#     reader=csv.DictReader(f)

#     for row in reader:
#         print(row)