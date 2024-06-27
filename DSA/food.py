st="*HH*HHH"
c=0

for i in range(len(st)):
    if st[i]=="*":
        c=2
    elif st[i]=="H":
        c-=1
    if c<0:
        print("N0")
        break
       
print("YES")