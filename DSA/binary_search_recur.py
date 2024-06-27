def recur(low,high,l,target):
    if low>high:
        return -1
    mid=low+(high-low)//2
    if l[mid]==target:
        return mid
    elif l[mid]<target:
        return recur(mid+1,high,l,target)
    else:
        return recur(low,mid-1,l,target)

l=[1,23,445,565,1000]
ans=recur(0,len(l)-1,l,565)
print(ans)
