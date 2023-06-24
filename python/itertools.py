from itertools import count
for i in count(20):
    print(i)
# for i in count(3):
#     print(i)
#     if i >=11:
#         break

from itertools import permutations

items = ['x', 'y']
x=list(permutations(items))
print(x)