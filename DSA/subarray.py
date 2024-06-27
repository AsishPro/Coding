l=[1,2,3,4,5]


for i in range(len(l)):
    for j in range(i,len(l)):
        for k in range(i,j+1):
            print(l[k],end='')
        print()


#time complexity = o(n^3)
#no.of subarrays = (n*(n+1))/2
        

#no.of subsequences = 2^n-1 