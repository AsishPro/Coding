def find(i,l):
    if i==len(l)-1:
        return True
    if l[i]<l[i+1] and find(i+1,l):
        return True
    return False

l=[1,2]
print(len(l))
print(find(0,l))
