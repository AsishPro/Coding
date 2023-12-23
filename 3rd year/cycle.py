# class Solution:
#     def dfs(self,i,v,B):
#         v[i]=1
#         for i in B[i]:
#             if v[i]==2:
#                 return 0
#             if v[i]==0:
#                 if not self.dfs(i,v,B):
#                     return 0
#         v[i]=2
#         return 
            
            
#     def solve(self, A, B):
#         v=[0 for i in range(A+1)]
#         for i in B:
#             if v[i]==0:
#                 if not self.dfs(i,v,B):
#                     return 0
#         return 1
# t=Solution()
# A=2
# B=[1,2,1,2]
# print(t.solve(A,B))
