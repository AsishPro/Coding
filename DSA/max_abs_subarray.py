
def subarrays(i,a,maxi,c,temp,res):
    print(i,res,'asish')
    if c>maxi:
        maxi=c
    if i==len(a):
        return maxi
    maxi=max(maxi,subarrays(i+1,a,maxi,c,a[i],res))
    
    if abs(temp-a[i])<=1:
        # print(i,temp,a[i],res)
        # min(temp,a[i])
        maxi=max(maxi,subarrays(i+1,a,maxi,c+1,temp,res+[a[i]]))

    return maxi
    

def pickingNumbers(a):
    
    res=[]
    return subarrays(0,a,-1,0,a[0],res)
 

a=[12,13,13,20,10,12,11]
print(pickingNumbers(a))
    
              
            