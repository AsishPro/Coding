# floor: gratest number that is smaller than or equal to target.
# arr= [2,3,5,9,14,16,18] == end in binary searchh 
#  start target end -- condition violated --> end target start
# start = least number greater than target (ceiling)
# end = greatest number less than target (floor)
# when condition violated s=e+1
# 5,8 search for 6

#if target greatest than largest number in array reutnr -1
#if 


l=[2,3,5,9,14,16]
target=17
low=0
high=len(l)-1 

while low<=high:
    mid=low+(high-low)//2
    print(mid)
    if l[mid]==target:
        print(mid,l[mid])
        break
    elif l[mid]<target:
        low=mid+1
    else:
        high=mid-1

print(low,high)
# print(l[low],l[high])
    