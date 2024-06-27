s='asheaaesha'

#remove all a's using recursion 

ans=''
def recur(s,i,ans):
    if i==len(s):
        return ans
    if s[i]!='a':
        ans+=s[i]
    return recur(s,i+1,ans)

# ans=recur(s,0,ans)
# print(ans)


#without using argument

def recur2(s,i):
    ans=''
    if i==len(s):
        return ans
    
    if s[i]!='a':
        ans+=s[i]

    ans+=recur2(s,i+1)
    return ans

ans=recur2(s,0)
print(ans)

