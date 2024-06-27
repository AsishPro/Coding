def bubble(r,s,l):
    if r==0:
        return
    if s<r:
        if l[s]>l[s+1]:
            l[s],l[s+1]=l[s+1],l[s]
        bubble(r,s+1,l)
    else:
        bubble(r-1,0,l)

l=[5,4,3,2,1]
bubble(4,0,l)
print(l)
