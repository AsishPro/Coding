# def merge(nums1, m, nums2, n):
#         i=0
#         j=0
#         while i<m and j<n:
#             if nums1[i]>nums2[j]:
#                 temp=nums1[i]
#                 nums1[i]=nums2[j]
#                 nums2[j]=temp
#                 i+=1
#             else:
#                 i+=1
#         while i<(m+n) and j<n:
#             print(i,j,nums1[i],nums2[j])
#             nums1[i]=nums2[j]
#             j+=1
#             i+=1
#         print(nums2)
#         print(nums1)
# merge([1,2,3,0,0,0],3,[2,5,6],3)
nums=[5,6,1]
l=[2,3,5]
nums+=l
print(nums)
nums.sort()
print(nums)