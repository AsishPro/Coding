def steps(g,dp):
    if g<0:
        return 0
    if dp[g]!=-1:
        return dp[g]
    if g==0:
        dp[g]=1
        return 1
    dp[g]=steps(g-1,dp)+steps(g-2,dp)
    return dp[g]


n=4
dp=[-1 for i in range(n+1)]
steps(n,dp)
print(dp)