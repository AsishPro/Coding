import re

pattern = r".+@[^-^_].+"
str="aishs@manoj"
if re.match(pattern, str):
    print("Match 1")
