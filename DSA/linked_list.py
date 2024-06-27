class Node:
    def __init__(self,val=0,next=None):
        self.val=val
        self.next=next

for i in range(100):
    a=Node(i)[10]
    print(a.val)