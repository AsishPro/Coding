def binary(arr,s,e,x):
  if(s<=e):
    mid=(s+e)//2
    if(arr[mid]==x):
      return mid
    elif(arr[mid]>x):
      return binary(arr,s,mid-1,x)    
    else:
      return binary(arr,mid+1,e,x)
  else:
     return -1

s=[1,2,3,78,100]
print(binary(s,0,len(s)-1,100))