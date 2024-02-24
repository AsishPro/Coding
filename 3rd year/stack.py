st=[]
st+=["a",'b','c']
i="c"
if (st[-1]=='{' and i=='}') or (st[-1]=='(' and i==')') or (st[-1]=='[' and i==']'):
    print("yes")
else:
    print("no")
