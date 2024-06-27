
def find_sub(ans,l,i,temp):
    if i==len(l):
        ans.append(temp[:])
        return
    
    find_sub(ans,l,i+1,temp)
    
    temp.append(l[i])
    find_sub(ans,l,i+1,temp)
    temp.pop()


    
l=['a','b','c']
# 1,2,3,12,13,23,123

ans=[]
temp=[]
find_sub(ans,l,0,temp)
# print(ans)

for i in ans:
    for j in i:
        print(j,end='')
    print()