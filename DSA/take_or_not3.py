def recur(i,l,temp,res):
    
    if len(temp)==3: 
        # if temp not in res:
        res.append(temp.copy())
        return
    if i==len(l):
        return 0
    recur(i+1,l,temp,res)

    if len(temp)==0 or temp[-1]<l[i]:
        temp.append(l[i])
        recur(i+1,l,temp,res)
        temp.pop(-1)
        

res=[]
temp=[]
l=[2,5,3,4,1]
recur(0,l,temp,res)
temp=[]
recur(0,l[::-1],temp,res)
print(res)
    

