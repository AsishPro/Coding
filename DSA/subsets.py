def subsets(l,i,ans):
    if i==len(l):
        print(ans)
        return 
    subsets(l,i+1,ans)
    subsets(l,i+1,ans+l[i])

l='abc'
ans=''
subsets(l,0,ans)