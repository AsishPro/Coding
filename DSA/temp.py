# def t1(temp):
#     temp=[]
#     for i in range(3):
#         temp.append(i)
# def t2(temp):
#     for i in range(3):
#         temp.append(i)

# temp=[]
# t1(temp)
# print(temp)
# t2(temp)
# print(temp)

a=[1,2,3,4]
z=a[::]
z[1]=3
print(z)
print(a)