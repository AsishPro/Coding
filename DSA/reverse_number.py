import math
def reverse(n,sum):
    if n%10==n and n==0:
        return sum
    # print(n%10,end='')

    sum=sum*10+(n%10)
    return reverse(n//10,sum)

n=1824
print(int(math.log10(n))+1)
sum=0
print(reverse(n,sum))