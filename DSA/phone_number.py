def digi(l,ans,start,m):
    res=[]
    if len(ans)==len(l):
        # print(ans)
        return ans
    for i in range(start,len(l)):
        print(i)
        for j in m[l[i]]:
            res.append(digi(l,ans+j,i+1,m))
    return res

m={2:['a','b','c'],3:['d','e','f'],4:['g','h','i'],5:['j','k','l'],6:['m','n','o'],7:['p','q','r','s'],8:['t','u','v'],9:['w','x','y','z']}

digits='23'
l=[int(i) for i in digits]
# print(l)
ans=''
print(digi(l,ans,0,m))