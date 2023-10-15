import numpy as np
def create(matrix,c,d,r,p):
    def find(matrix):
        for i in range(3):
            for j in range(3):
                if(matrix[i][j]==0):
                    c=i
                    d=j
        return c,d
    def left(matrix,c,d):
            if d > 0:
                print(r)
                print("left")
                matrix1=np.copy(matrix)
                temp1=matrix1[c][d-1]
                matrix1[c][d-1]=matrix1[c][d]
                matrix1[c][d]=temp1
                c,d=find(matrix1)
                print(c,d)
                print(matrix1)
                create(matrix1,c,d,r+1,p)
    def right(matrix,c,d):
            if d < 2 :  
                print(r)
                print("right")
                matrix1=np.copy(matrix)  
                temp1=matrix1[c][d+1]
                matrix1[c][d+1]=matrix1[c][d]
                matrix1[c][d]=temp1
                c,d=find(matrix1)
                print(c,d)
                print(matrix1)
                create(matrix1,c,d,r+1,p)
    def up(matrix,c,d):
            if c > 0:
                print(r)
                print('up')
                matrix1=np.copy(matrix)
                temp1=matrix1[c-1][d]
                matrix1[c-1][d]=matrix1[c][d]
                matrix1[c][d]=temp1
                c,d=find(matrix1)
                print(c,d)
                print(matrix1)
                create(matrix1,c,d,r+1,p)
    def down(matrix,c,d):
            if c < 2:  
                print(r)
                print('down')
                matrix1=np.copy(matrix)  
                temp1=matrix1[c+1][d]
                matrix1[c+1][d]=matrix1[c][d]
                matrix1[c][d]=temp1
                c,d=find(matrix1)
                print(c,d)
                print(matrix1)
                create(matrix1,c,d,r+1,p)
    if r>p:
        return 0
    c,d=find(matrix)
    left(matrix,c,d)
    right(matrix,c,d)
    up(matrix,c,d)
    down(matrix,c,d)
matrix = [[1, 8, 3], [5, 7, 4], [6, 2, 0]]
c=0
d=0
r=0
p=2
create(np.array(matrix),c,d,r+1,p)