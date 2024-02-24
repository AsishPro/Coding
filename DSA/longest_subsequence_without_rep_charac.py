class Solution(object):
    def recur(self,i,m,s,ans):
        if i==len(s):
            return len(m)
        a=self.recur(i+1,m,s,ans)
        b=0
        print(m,i,s[i],a,b)
        if s[i] not in m:
            m[s[i]]=1
            b=self.recur(i+1,m,s,ans)
            print(m,i,a,b)
            m.pop(s[i])
        ans=max(a,b)
        return ans
    def lengthOfLongestSubstring(self, s):
        m={}
        ans=0
        ans=self.recur(0,m,s,ans)
        print(m)
        print(ans)
    
        
a=Solution()
s='abcabcbd'

a.lengthOfLongestSubstring(s)

