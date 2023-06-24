s="qA2#"
# print(*(l*2 for l in s))
print(any(l.isalnum() for l in s))
print(any(l.isalpha() for l in s))
print(any(l.isdigit() for l in s))
print(any(l.islower() for l in s))
print(any(l.isupper() for l in s))

