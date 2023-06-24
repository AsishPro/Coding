n=int(input("Enter the number: "))
count=0
for i in range(2,n+1):
    count=0
    for j in range(2,n+1):
        if(i%j==0):
           count=count+1
    if(count==1):
        print(i)
  