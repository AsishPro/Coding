class Solution(object):
    def prime(self,k):
        c=0
        i=1
        while i<=int((k**(0.5))):
            if k%i==0:
                c+=1
                if c==2:
                    break
            i+=1
        return c
    def countPrimes(self, n):
        i=2
        count=0
        while i<=n:
            k=self.prime(i)
            if k<=1:
                print(i)
                count+=1
            i+=1
        return count

ans=Solution()
print(ans.countPrimes(30))