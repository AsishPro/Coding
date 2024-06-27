def combi(target,coins,dp):
    if target==0:
        return 0
    if dp[target]!=999:
        return dp[target]
    for i in coins:
        if target-i>=0:
            x=1+combi(target-i,coins,dp)
            dp[target]=min(dp[target],x)
    return dp[target]
    

target=11
dp=[999]*(target+1)
dp[0]=0
coins=[1,2,5]

combi(target,coins,dp)
print(dp)