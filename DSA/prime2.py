
i=3
n=10
l=[2]
c=0
while i<n:
    c=0
    for j in l:
        if i%j==0 and i!=j:
            c+=1
    if c==0:
        l.append(i)
    i+=1
print(l)

    
