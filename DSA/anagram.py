
m={}
l = ["eaat","tea","tan","ate","nat","bat"]
for i in l:
    a=[0]*26
    for j in i:
        a[ord(j)-ord('a')]+=1
    temp=''
    for k in range(len(a)):
        if a[k]!=0:
            temp+=chr(k+ord('a'))
    if temp not in m:
        m[temp]=[i]
    else:
        m[temp].append(i)
l=[]
for i in m:
    l.append(m[i])
print(l)

# l= ["eat","tea",""]

# c=0
# # 
# for i in l:
#     c=0
#     for j in i:
#         c+=ord(j)-ord('a')
#     print(c)
 
