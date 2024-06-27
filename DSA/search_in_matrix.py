
def binary_search(l,low,high):
    while low<=high:
        mid= low+(high-low)//2
        if l[mid]==target:
            return mid
        elif l[mid]<target:
            low=mid+1
        else:
            high=mid-1
    return high
    #low = least element greater than target
    #high= highest element below target

l=[[10,20,30,40],[11,25,35,45],[28,29,37,49],[33,34,38,50]]

for i in l:
    print(i)

target=33

r=0
c=len(l[0])-1
while (r<len(l) and c>=0):
    pot=binary_search(l[r],0,c)
    print(pot)
    if l[r][pot] == target:
        print(f"ANSWER FOUND at {r},{c}")
        break
    c=pot
    if l[r][c]<target:
        r+=1
    else:
        c-=1
    print(r,c)
print(r,c)