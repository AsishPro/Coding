import numpy as np
#topological sort is done using dfs

def dfs():
    pass


n=8
e=[[0,1],[1,2],[2,3],[2,4],[5,6],[5,7]]

v=[0 for i in range(n)]
edges=[[] for i in range(n)] #adjacency list
for i in e:
    v[i[0]]+=1
    v[i[1]]+=1
    edges[i[0]].append(i[1])
    edges[i[1]].append(i[0])
for i in range(len(v)):
    print(i,v[i])

for i in range(len(edges)):
    print(f"{i} - {edges[i]}")
m=0
for i in range(n):
    for j in range(i+1,n):
        print(i,j,m)
        if [i,j] or [j,i] in e:
            m=max(m,v[i]+v[j]-1)
        else:
            m=max(m,v[i]+v[j])

print(m)