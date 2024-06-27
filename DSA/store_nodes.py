class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next      


list1=ListNode(2)
list1.next=ListNode(5)
list1.next.next=ListNode(7)
list1.next.next.next=ListNode(14)


new=None
temp=new

#note : never assign new or iterating pointer to new.
while list1:
    if temp==None:    
        new=ListNode(list1.val)
        list1=list1.next
        temp=new
    else:
        new.next=ListNode(list1.val)
        list1=list1.next
        new=new.next

ans=temp

kj=None
temp=kj

# so we can reassign node.
# old list will always retain old reference.
while ans:
    print(ans.val)
    ans=ans.next
