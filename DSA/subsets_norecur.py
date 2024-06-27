l=[1,2,3]
ans=[[]]
for i in l:
    n=len(ans)
    temp=ans[::]
    for j in range(n):
        lt=[]
        lt+=ans[j]
        lt.append(i)
        ans.append(lt)
print(ans)