def linearsearch(l,i,target):
    if i==len(l):
        return -1
    if l[i]==target:
        return i
    return linearsearch(l,i+1,target)
def findallindex(l,i,target,res):
    if i==len(l):
        return res
    if l[i]==target:
        res.append(i)
    return findallindex(l,i+1,target,res)
    


# findall without passing res as argument
def findallindex2(l,i,target):
    res=[]
    if i==len(l):
        return []
    if l[i]==target:
        res.append(i)
    return res+findallindex2(l,i+1,target)
    

l=[123,4,454,54,454,5,454,343,2]
# print(linearsearch(l,0,2))

# res=[]
# print(findallindex(l,0,454,res))
# #without taking return also list updated because its reference 
# print(res)
    
print(findallindex2(l,0,454))