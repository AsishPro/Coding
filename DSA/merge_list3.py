class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


list1=ListNode(1)
list1.next=ListNode(2)
list1.next.next=ListNode(4)


head=ListNode()
new=head

temp=ListNode()
temp.val=2

head=temp

print(new.val)
