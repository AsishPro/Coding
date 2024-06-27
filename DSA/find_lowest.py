# to find minimum in an array.
#not for dupli

# to find pit in array
l=[3,2,1,2,3,4,5,6]

low=0
high=len(l)-1

while low<high:
    mid=low+(high-low)//2
    if l[mid]<l[mid+1]:
        high=mid
        # l[mid]>l[mid+1]
    else:
        low=mid+1

print(low,high)


