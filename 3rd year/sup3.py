num=[11,33,45]
t=[0 for i in range(10)]
for i in num:
    k=str(i)
    t[int(k[0])]+=1
    t[int(k[1])]+=1
for i,j in enumerate(t):
    print(i,j)