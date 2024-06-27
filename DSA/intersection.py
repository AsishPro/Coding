class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next      


headA=ListNode(4)
headA.next=ListNode(1)
headA.next.next=ListNode(8)
inter=headA.next.next
headA.next.next.next=ListNode(4)
headA.next.next.next.next=ListNode(5)


headB=ListNode(5)
headB.next=ListNode(6)
headB.next.next=ListNode(1)
headB.next.next.next=headA.next.next



temp1=headA
temp2=headB

while temp1!=temp2:

    if temp1==temp2:
        print(temp1.val)
        break
    
    temp1=temp1.next if temp1 else headB
    temp2=temp2.next if temp2 else headA


# print(None)