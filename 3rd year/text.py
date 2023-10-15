def find(i):
    c=0
    t=0
    print(i)
    temp=[' ','.']
    for j in range(len(i)):
        print(t)
        t+=1
        if (i[j]==' ' and i[j-1] not in temp) or (i[j]=='.' and i[j-1] not in temp):
          c+=1
    if i[-1] not in temp:
        c+=1
    return c


f=open('text.txt','r')
c=0
word=0
for i in f:
    c+=1
    k=find(i)
    # print(k)
    # k=i.split(" ")
    print(k)
    word+=k
print(c,word)
