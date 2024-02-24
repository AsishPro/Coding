import numpy as np
m=np.array([[1,2,3],[4,5,6],[7,8,9]])

print(m)

res=[]
for j in range(len(m[0])):
    l=[]
    for i in range(len(m)):
        print(i,j)
        l.append(m[i][j])
    l=l[::-1]
    res.append(l)
return res
    