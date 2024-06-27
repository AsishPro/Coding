def dice(p,target,custom):
    l=[]
    if target==0:
        l.append(p)
        return l
    i=1
    while i<=custom and i<=target:
        l+=dice(p+str(i),target-i,custom)
        i+=1
    return l
    

#custom face
print(dice('',6,9))