
# function to return key for any value
def get(val):
    for key, value in d1.items():
        if val == value:
            return key
 
    return "key doesn't exist"
 

lst=input()
d1={}
for i in lst:
    if i in d1:
      d1[i]=d1[i]+1
    else:
      d1[i]=1
x=get(max(d1.values()))
print(x,d1[x])