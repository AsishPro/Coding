l=[2,3,5,9,14,16]
a=2
b=3

target=6
low=0
high=len(l)-1 


# if index not found then binary search will find high=  highest element less than target.

# low= least element greater than target .

while low<=high:
    mid=low+(high-low)//2
    print(mid)
    if l[mid]==target:
        print(mid,l[mid])
        break
    elif l[mid]<target:
        low=mid+1
    # if l[mid]>target:
    #     low=mid+1
    # else:
        high=mid-1
print(low,l[mid])
    