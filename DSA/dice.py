def dice(p,target):
    if target==0:
        print(p)
        return 
    i=1
    while i<=6 and i<=target:
        dice(p+str(i),target-i)
        i+=1
    


dice('',4)