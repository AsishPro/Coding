import numpy as np
def matrix_input():
    m=[]
    r=int(input("number of rows of matrix: "))
    c=int(input("number of columns: "))
    for i in range(r):    
        temp=input(f"Enter row {i+1} with   spaces: ").split()
        print(temp)
        m.append([int(x) for x in temp])
    return np.array(m)

# #for custom input
# m=matrix_input()
# print(m)

m=np.array([[1,8,3],[5,-1,4],[6,2,1]])
k=np.where(m==-1)
i1,i2=np.where(m==-1)   #finding -1 location
a,b=i1[0],i2[0]  
print(a,b)
print(k[0][0],k[1][0])

print(tuple(map(tuple,m)))