lst = []
  
n=int(input())
  
for i in range(0, n):
    ele = int(input())
    lst.append(ele)
    
lst.sort()
print(lst)
count=0
k=0
for i in range(0,n):
    i=i+count
    count=0
    for j in range(i,n):
         if lst[i]==lst[j]:
              count=count+1
    k=k+count//2
    
print(k)