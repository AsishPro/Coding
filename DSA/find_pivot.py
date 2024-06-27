# l=[1,2,3,4,5,1,2,3]

l=[5,0,1,2,3]

low=0
high=len(l)-1

ans=-1

while low<high:
    mid=low+(high-low)//2
    if l[mid]>l[mid+1]:
        ans=mid
        print(mid,l[mid],'greater')
        break
    if l[mid-1]>l[mid]:
        ans=mid-1
        print(mid-1,l[mid-1],'less')
        break
    if l[mid]<l[mid+1] and l[low]>l[mid]:
        high=mid
    else:
        low=mid+1

print(low,high)

