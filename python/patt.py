m=3
n=4
res=['feed', 'thed', 'og']
for j in range(n):
    for i in range(m):
        if(j<len(res[i])):
            print(res[i][j],end="")
        else:
            print("",end="")        
    print(" ",end="")