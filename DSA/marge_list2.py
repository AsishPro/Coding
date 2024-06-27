class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


list1=ListNode(1)
list1.next=ListNode(2)
list1.next.next=ListNode(4)


list2=ListNode(1)
list2.next=ListNode(3)
list2.next.next=ListNode(4)




# head=ListNode(54)
# temp=head


# head.next=ListNode(2)
# head=head.next
# head.next=ListNode(5)


# print(temp.next.next.val)
head=ListNode()
new=head

while list1 and list2:
    if list1.val<list2.val:
        head.val=list1.val
        list1=list1.next
    else:
        head.val=list2.val
        list2=list2.next
    if list1 or list2:
        head.next=ListNode()
        head=head.next

if list1:
    head.val=list1.val
    head.next=list1.next
else:
    head.val=list2.val
    head.next=list2.next

while new:
    print(new.val,end=' ')
    new=new.next

            


        