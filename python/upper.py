s=input()
str="ABCDEFGHIJKLMNOPQRST"
k=""
for i in range(0,len(s)):
        if s[i] not in str:
            k=k+s[i].upper()
        else:
           k=k+s[i].lower()
print(k)

