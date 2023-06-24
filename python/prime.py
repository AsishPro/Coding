import math

def prime_factors(n):
    factors = []
    # Check for 2 as a factor and divide the number by 2 repeatedly
    while n % 2 == 0:
        factors.append(2)
        n //= 2
    
    # Check for odd prime factors up to square root of n
    for i in range(3, int(math.sqrt(n))+1, 2):
        while n % i == 0:
            factors.append(i)
            n //= i
    
    # If n is a prime greater than 2, add it to the list of factors
    if n > 2:
        factors.append(n)
    
    return factors


n=int(input())
print(prime_factors(n))