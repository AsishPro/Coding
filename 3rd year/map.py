from collections import defaultdict
words =["word","good","best","word"]

m=defaultdict(int)
for i in words:
    m[i]+=1
print(dict(m))