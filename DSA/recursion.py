#same function with same functionality calling itself instead of creating new functions of same functionality 

# function stays in stack until it completes execution.

# base condition is where is recursive function stops calling itself

#why recursion : to solve complex problems in simple way
# any recursion can be converted to iterations and vice versa
#print n numbers in loop - o(1) but using recursion space - o(n)

def recur(i):
    if i==5:
        return 
    recur(i+=1)
