def pali_check(n,i,j):
    if i>j:
        return True
    if n[i]!=n[j]:
        return False
    return pali_check(n,i+1,j-1)

n=12321
res=str(n) if type(n)==type(2) else n
print(pali_check(res,0,len(res)-1))