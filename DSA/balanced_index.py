l=[1,2,3,4,6]

# #left sum= right sum

# left=[0 for i in range(len(l))]
# right=[0 for i in range(len(l))]

# prev=0
# for i in range(len(l)):
#     left[i]=prev+l[i]
#     prev=left[i]

# prev=0
# for i in range(len(l)-1,-1,-1):
#     right[i]=prev+l[i]
#     prev=right[i]

# index=-1
# for i in range(1,len(l)-1):
#     if left[i-1]==right[i+1]:
#         index=i
#         break

# print(index)


sum=sum(l)


small_sum=0
for i in range(len(l)):
    small_sum+=l[i]
    if sum-small_sum+l[i]==small_sum:
        print(i)
        break

    
