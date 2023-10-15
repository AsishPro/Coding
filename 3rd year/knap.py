# import numpy as np
# arr=[1,2,3,4,5]
# k=np.array(arr)

# print(max(k[2:4]))
class Solution(object):
    def recur(self,arr,i,k):
        if i==len(arr):
            return 0
        index=min(i+k-1,len(arr)-1)
        temp=max(arr[i:index])*k
        return max(arr[i]+self.recur(arr,i+1,k),temp+self.recur(arr,min(i+k,len(arr)-1),k))
    def maxSumAfterPartitioning(self, arr, k):
        
        return self.recur(arr,0,k)
a=Solution()
arr=[12,3,4,5]
a.maxSumAfterPartitioning(arr,2)