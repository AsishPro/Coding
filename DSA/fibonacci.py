#recurance relation : when we write recursion in formula. 

def fibo(n):
    if n<=1:
        return n
    return fibo(n-1)+fibo(n-2)

print(fibo(50))
# for i in range(5):
#     print(fibo(i))