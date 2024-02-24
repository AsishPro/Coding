
import copy

def modify(l):
    l[1]=15
    print(l)

l=[[1,1,1],[1,0,1],[1,1,1]]
# l=[2,3,4,5,6,7,8]
# modify(l.copy())
k=copy.deepcopy(l)
k[1][0]=14
print(k)
print(l)