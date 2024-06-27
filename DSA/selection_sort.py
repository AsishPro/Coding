def selection(l,r,s,maxi):
    if r==0:

        return
    if s<=r:
        if l[s]>l[maxi]:
            maxi=s
        selection(l,r,s+1,maxi)
    else:
        temp=l[maxi]
        l[maxi]=l[r]  
        # for i in range(maxi,r):
        #     l[i]=l[i+1]
        l[r]=temp
        selection(l,r-1,0,maxi)
    
l=[5,2,3,19,1,0]
selection(l,len(l)-1,0,-1)
print(l)
