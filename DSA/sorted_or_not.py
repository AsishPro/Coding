def sorted(i,l):
    if i==len(l)-1:
        return True
    if l[i]<=l[i+1]:
        return sorted(i+1,l)
    return False

def sorted2(i,l):
    if i==len(l)-1:
        return True
    if l[i]>l[i+1]:
        return False
    return sorted(i+1,l)

l=[1,2,3,4,5,6,2]
print(sorted2(0,l))
    

