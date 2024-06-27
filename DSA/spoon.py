# cook your dish here
import numpy as np

t=int(input())
while t:
    m,n=map(int,input().split())
    l=[]
    
    f=0
    for i in range(m):
        l+=[j.lower() for j in input().split()]
        if 'spoon' in l[-1]:
            print("There is a spoon!")
            f=1
    # l=np.array(l)

    print(l)
    
    if f==0:
        for j in range(n):
            s=''
            for i in range(m):
                print(i,j,l[i][j])
                s+=l[i][j]
                
            if 'spoon' in s:
                print("There is a spoon!")
                f=1
                break
    if f!=1:
        print("There is indeed no spoon!")
    
    t-=1