
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


head=ListNode(1)
head.next=ListNode(2)
head.next.next=ListNode(3)
head.next.next.next=ListNode(4)
head.next.next.next.next=ListNode(5)
# print(head.next.next.next.next.next)

 # 1 2 3 4 5 
curr=head
old=None
while curr:
    # if curr.next==None:
    #     res=curr
    # else:
    #     res=curr
    new=curr.next
    curr.next=old
    old=curr
    curr=new
# curr.next=old
    # print(old.val,curr.val,new.val)
        
print(old.val)
