import math

n=int(input())
tem=n
count=0
while(n!=0):
    count+=1
    n=n//10
n=tem
sum=0
while(n!=0):
    sum=sum+(n%10)**count
    n=n//10
if(sum==tem):
    print("Armstrong")
else:
    print("Not Armstrong")

