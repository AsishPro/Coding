def sumi(n):
    if n%10==n and n==0:
        return 0
    return (n%10)+sumi(n//10)

print(sumi(543))