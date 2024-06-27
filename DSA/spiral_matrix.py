import numpy as np 

a = [[1, 2, 3],[4, 5, 6],[7,8,9]]

r=[0,1,0,-1]
c=[1,0,-1,0]
x=0
y=0
cm=0

v=np.full((len(a),len(a[0])),0)
print(v)

f1=0
f2=0
print(a[x][y])
for i in range(len(a)*len(a[0])):

    
    if v[x+r[cm]][y+c[cm]]==1:
        cm+=1
        cm=cm%4
    print(x,y,a[x][y])
    v[x][y]=1
    x=x+r[cm]
    y=y+c[cm]
    
    if y==len(a[0])-1 and f1==0:
        f1=1
        cm+=1    
    elif x==len(a)-1 and f2==0:
        f2=1
        cm+=1
    elif y==0 and f1==1:
        f1=0
        cm+=1
        print(r[cm],c[cm])
    
    cm=cm%4
    

    
    