def recur(l,start,end):
    # print(start,end)
     
    if end==len(l):
        start+=1
        end=start
    if end==len(l) and start==len(l):
        return
    
    # print(start,end)
    for i in range(start,end+1):
        print(l[i],end='')

    print()
    recur(l,start,end+1)

l=[1,2,3,4,5]
# print(l[:],l[::])
recur(l,0,0)