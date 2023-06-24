
for i in range(1,5):
    for j in range(1,5):
        # 1 - 2 -0
        # 2 - 3 -1
        # 3 - 4 -0
        # 4 - 5 -1
        if(i%2==0):
          j=j+1
        print(j%2,end='')
    print()