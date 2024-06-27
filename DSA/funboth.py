def funboth(n):
    if n<0:
        return 
    print(n)
    # print this 
    # afthe calling this that will print n-1 5,4,3,2,1,0 and then next print line execute print 0
    funboth(n-1)
    print(n)    

funboth(5)
