n=int(input("Enter the Number: "))
temp=n
k=0
count=0
while(n!=0):
    k=k*10+n%10
    count=count+1
    n=n//10

n=temp
r1=n%10
r2=k%10

sum=r1
k=k//10
count=count-2
while(count):
    sum=sum*10+k%10
    k=k//10
    count=count-1
    
sum=sum*10+r2
print(sum)
