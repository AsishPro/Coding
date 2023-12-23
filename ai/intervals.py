l=[[1, 3], [8, 10],[2, 6], [15, 18]]
res=[]
l.sort()
print(l)
res.append(l[0])

for i in range(1,len(l)):
    if l[i][0]<res[-1][1]:
        temp=[res[-1][0],max(l[i][1],res[-1][1])]
        print(temp)
        res=res[:-1]
        res.append(temp)
    else:
        res.append(l[i])

    

print(res)
