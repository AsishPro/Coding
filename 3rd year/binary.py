n=10
x=7
res=1
c=0
while n!=0:
    c+=1
    if (n%2)!=0:
        # print(res,x)
        res *= x
    x=x*x
    print(x)
    n>>=1
print(res)
print(c)