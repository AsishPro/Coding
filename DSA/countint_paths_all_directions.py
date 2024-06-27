#adding diagonal possible

def paths(maze,p,i,j,m,n):
    lt=[]
    
    if i<0 or j<0:
        return []
    if maze[i][j]==True:
        return []
        
    maze[i][j]=True

    
    if i==m-1 or j==n-1:
        if i==m-1:
            p+='R'*(n-j-1)
        else:
            p+='D'*(m-i-1)
        # print(p)
        lt.append(p)
        return lt
    
    if i-1>=0:
        lt+=paths(maze,p+'U',i-1,j,m,n)
    if j-1>=0:
        lt+=paths(maze,p+'L',i,j-1,m,n)
    lt+=paths(maze,p+'D',i+1,j,m,n)
    lt+=paths(maze,p+'R',i,j+1,m,n)
    
    maze[i][j]=False

    return lt





m=3 
n=3
maze=[[False,False,False],[False,False,False],[False,False,False]]


p=''
print(paths(maze,p,0,0,m,n))


