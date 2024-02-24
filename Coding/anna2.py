n=int(input()) 
# a,b,c = (int(x) for x in input().split())
lst=[]
for i in range(0,n):
    tup = tuple((x) for x in input().split())[:3]
    lst.append(tup)
print(sorted(lst))