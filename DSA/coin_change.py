def combi(i,coins,target,res,temp):
    if target<0 or i>=len(coins):
        return
    if target==0:
        res.append(temp)
        return 

    combi(i+1,coins,target,res,temp)
    if target-coins[i]>=0:
        combi(i,coins,target-coins[i],res,temp+[coins[i]])

coins=[1,2,5]
target=11
res=[]
temp=[]
ans=[]
combi(0,coins,11,res,temp)
print(res)

temp=res[0]
for i in res:
    if len(i)<len(temp):
        temp=i


#TLE





