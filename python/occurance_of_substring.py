s="thisisasubstring"
k="substring"
for i in range(len(s)):
    if(s[i:i+len(k)]==k):
        print(i)
