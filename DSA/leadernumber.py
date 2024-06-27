#given array of integers find the leader numbers 
# leader number: the number that is strictly greater than all numbers towards its right?

# 1.using stack 
# 2. keep track of max from rhs.

l=[40,72,54,60,66,31,37,53,12,24,18,7,2,3,1]

# maxi=l[-1]
# for i in l[::-1]:
#     if i>=maxi:
#         maxi=i
#         print(maxi)


st=[]

for i in l[::-1]:
    if len(st)==0 or i>st[-1]:
        st.append(i)
print(st)

