#adding diagonal possible

def paths(p,i,j,m,n):
    lt=[]
    if i==m-1 or j==n-1:
        if i==m-1:
            p+='R'*(n-j-1)
        else:
            p+='D'*(m-i-1)
        # print(p)
        lt.append(p)
        return lt
    lt+=paths(p+'C',i+1,j+1,m,n)
    lt+=paths(p+'D',i+1,j,m,n)
    lt+=paths(p+'R',i,j+1,m,n)
    return lt




m=3 
n=4
p=''
print(paths(p,0,0,m,n))


