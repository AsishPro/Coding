
def recur(r,s):
    if r==0:
        return 
    if s<=r:
        
        recur(r,s+1)
        print('*',end='')
    else:
        
        recur(r-1,0)
        print()
    
    
r=5
s=0
recur(r,s)