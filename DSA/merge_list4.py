class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next      

list1=ListNode(5)
list1.next=ListNode(7)
list1.next.next=ListNode(9)


list2=ListNode(3)
list2.next=ListNode(4)
list2.next.next=ListNode(8)
list2.next.next=ListNode(10)


temp=ListNode()

if list1.val<list2.val:
    temp=list1
    list1=list1.next
else:
    temp=list2
    list2=list2.next

new=temp

# print(list2.val)

while list1 and list2:
    while list1 and list2 and list1.val<list2.val:
        temp.next=list1
        list1=list1.next
        temp=temp.next
    while list1 and list2 and list2.val<list1.val:
        temp.next=list2
        list2=list2.next
        temp=temp.next

if list1:
    temp.next=list1
if list2:
    temp.next=list2

while new:
    print(new.val,end=' ')
    new=new.next