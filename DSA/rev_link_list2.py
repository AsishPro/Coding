while curr.next:
    new=curr.next
    curr.next=old
    old=curr
    curr=new
curr.next=old
        