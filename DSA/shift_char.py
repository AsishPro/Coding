s='middle-Outz'
res=''
k=2
print(ord('a'))
print(97+26)
for i in s:
    z=((ord(i)-ord('a')+k)%26)
    print(i,ord(i),z,chr(z+97))
    
    # if i>='a' and i<='z':
    #     res+=(i+k)
