def zeros(n,count):
    if n%10==n and n==0:
        return count
    if n%10==0:
        count+=1
    return zeros(n//10,count)

print(zeros(90090,0))
    