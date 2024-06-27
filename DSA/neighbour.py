# given an array of n integers wwhere each element is either +1 or -1 from its neighbouring element, find the index of first occurance of a key, avoiding the linear search.
import numpy as np

a='asishmanoj'
b='reddyyadav'
c='kumaraswam'

l=[a,b,c]

l=np.array(l)
n=10
m=3

for j in range(n):
    s=''
    for i in range(m):
        s+=l[i][j]
    if 'spoon' in s:
        print("There is a spoon!")
        f=1
        break
    