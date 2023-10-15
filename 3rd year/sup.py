def find(i,l,num):
    if i>=len(num):
        return 0
    digit = list(map(int,str(num[i])))
    if any(item in l for item in digit):
        l+=digit
        l=list(set(l))
        return 1+find(i+1,l,num)
    return find(i+1,l,num)
    



num=[50,30,15,51,10,20,15]
count=1
for i,v in enumerate(num):
    l=[]
    k=str(v)
    l+=[int(k[0]),int(k[1])]
    t=find(i+1,l,num)
    if count<t:
        count=t+1
print(count)


# d=[1,2,3]
# l=[3,4,5]
# if any(item in d for item in l):
#     d+=l
#     d=list(set(d))
# print(d)
