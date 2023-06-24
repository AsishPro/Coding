lst=[2,3,5,7,11,13,17,19]
count=0
cout2=0
for i in range(2,1001):
  count=0
  for j in range(0,8):
       if(i%lst[j]!=0):
         count+=1
  if count==8:
    cout2=cout2+1
print(cout2)