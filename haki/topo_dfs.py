 
def dfs(ans,edges,n):
    v[n]=1
    
    for i in edges[n]:
        if v[i]==0:
            dfs(ans,edges,i)  
    ans.append(n) 
    return ans

n=4
e=[[1,2],[2,3],[3,1]]
edges=[[] for _ in range(n)]
for i in e:
    edges[i[0]].append(i[1])

ans=[]

v=[0 for i in range(n)]
print(edges)
for i in range(n):     #loop taken because to check disconnected components
    if not v[i]:
        dfs(ans,edges,i)
print(ans[::-1])  #reversing order




        