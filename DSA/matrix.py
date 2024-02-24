import numpy as np
import copy
def dfs(m):
    m[1][0]=2

m=[[1,1,1],[1,0,1],[1,1,1]]
print(m[1])
# m[1]=[0]*len(m)
# for i in m:
#     print(i)

# for i in range(len(m)):
#     print(i)
#     for j in range(len(m[0])):
#         print(i,j)
#         if m[i][j]==0:
#              m[i]=[0]*len(m)
# print(m)
og=[row[:] for row in m]
og[1][0]=12
print(m)
# v=np.full((len(m),len(m[0])),-1)
# v[1,:]=1
# print(v)