def recur(sum,s,t,i):
    print(sum,i)
    if sum==t:
        return 1
    if sum>t or i==len(s):
        return 0
    return recur(sum,s,t,i+1)+recur(sum+s[i],s,t,i)


s=[1,3,5,7]
t=8
sum=0
ans=recur(sum,s,t,1)+recur(sum+s[0],s,t,0)
print(ans)