def paths(p,i,j,m,n):
    
    if i==m-1 or j==n-1:
        
        if i==m-1:
            p+='R'*(n-j-1)
        else:
            p+='D'*(m-i-1)
        print(p)
        return 1
    res=0
    res=paths(p+'D',i+1,j,m,n)
    res+=paths(p+'R',i,j+1,m,n)
    return res



m=3
n=4
p=''
print(paths(p,0,0,m,n))


