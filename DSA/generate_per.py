def per(t,start,res):
    if start==len(t):
        res.append(t)
        return 1
    c=0;
    for i in range(start,len(t)):
        s=t.copy()
        s[i], s[start]=s[start], s[i]
        c+=per(s,start+1,res)
    return c
  
res=[]
l=['a','b','c']

# # print(l[1:len(l)])
# b=1
# print(l[b+1:len(l)])
# print(l[:1:-1])
c=per(l,0,res)
print(c)
for i in res:
    print(i)

# nums=l
# print("ANS IS \n")
# print(len(res))
# for i in range(len(res)):
#     if res[i]==nums:
#         print(res[(i+1)%len(res)])
    