
def HCF(x,y):
    if(y%x==0):
        print(x)
    if y%x!=0:
        HCF(y%x,x)
    
a=int(input("Enter the first number: "))
b=int(input("Enter the Second number: "))
if(a<b):
    HCF(a,b)
else:
    HCF(b,a)