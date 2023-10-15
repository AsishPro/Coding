
def recur(l,i,prev,sum):
    if i==n-1:
        return l[i]-l[prev]
    elif i>n-1:
        return 999
    else:
        sum+=abs(abs(l[i]-l[prev])-min(recur(l,i+1,i,sum),recur(l,i+3,i,sum)))
        return sum
l=[4,12,13,18,10,12]
n=len(l)
print(recur(l,0,0,0))
