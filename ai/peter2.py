f = open('t2.txt','r')
list1 = [line.split() for line in f]

list2 = []

for line in list1:
    line.sort()
    if line and line[0] == '.':
        line.pop(0)

list1.sort()

for line in list1:
    x = ' '.join(line) + "."
    print(x)
    list2.append(x)
f = open('t3.txt','w')
for line in list2:
    f.write(line + '\n')