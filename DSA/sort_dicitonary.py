class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next      


list1=ListNode(10)
list1.next=ListNode(5)
list1.next.next=ListNode(2)


m=dict()
while list1:
    m[list1]=1
    list1=list1.next


for i in sorted(m.items(),key=lambda x:x[0].val):
    print(i[0].val)


d1=dict()

d1[4]=5
d1[5]=2
d1[6]=1




print(sorted(d1.items(),key=lambda x:x[0]))


