def permute(l,r,a):
    if l==r:
        return print("".join(a))
    for i in range(l,r):
        k=a.copy()
        k[l],k[i]=k[i],k[l]
        permute(l+1,r,k)


a= "123"
n = len(a)
a = list(a)
l=0
permute(0,n,a)

	
