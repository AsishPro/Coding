class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

a=ListNode(2)
print(a.val)
print(a.next)
a.next=ListNode(4)
a.next.next=ListNode(5)
k=a
k.next=ListNode(17)
print(k.val)
print(a.next.val)