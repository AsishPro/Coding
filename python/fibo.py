import math
fib=[0,1]
k=int(input())
for i in range(2,k+1):
    fib.append(fib[i-1]+fib[i-2])

print(fib(k+1))
