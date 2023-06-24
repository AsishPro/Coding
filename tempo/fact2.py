import time
def fact(n):
    if(n<=1):
        return 1
    else:
       return n*(fact(n-1))
start_time=time.time()
for i in range(0,200):
     print(i,fact(i))
end_time=time.time()
print(f"Maximum Recursion TIme is :{start_time-end_time}")    