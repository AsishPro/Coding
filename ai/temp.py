p1=[1,23,4545,45,65,665]
child=[-1]* len(p1)

child[2:5] = p1[2:5]
print(child)
child[2]=1
print(child)
print(p1)