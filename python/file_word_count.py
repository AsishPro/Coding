file=open("asish.txt","r")
c=file.read().split()
print(len(c))
d1={}

for w in file.read().split():
    if w in d1:
        d1[w]+=1
    else:
        d1[w]=1
print(d1)