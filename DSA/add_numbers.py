class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next      

list1=None
temp=None

for i in range(1):
    if list1==None:
        list1=ListNode(0)
        temp=list1
    else:
        list1.next=ListNode(0)
        list1=list1.next

list1=temp


# list2=None
# temp=None

# for i in range(4):
#     if list2==None:
#         list2=ListNode(9)
#         temp=list2
#     else:
#         list2.next=ListNode(9)
#         list2=list2.next

# list2=temp

list2=ListNode(7)
list2.next=ListNode(3)


temp=ListNode()
new=temp

carry=0
while list1 or list2:
    val=0
    val+=carry

    if list1:
        val+=list1.val
        list1=list1.next
    if list2:
        val+=list2.val
        list2=list2.next

    temp.val=val%10
    carry=val//10

    if val//10!=0 or list1 or list2:
        print(val,carry)
        temp.next=ListNode()
        temp=temp.next

# while list1:
#     temp.val=carry+list1.val
#     list1=list1.next
#     if list1:
#         temp.next=ListNode()
#         temp=temp.next

# while list2:
#     temp.val=carry+list2.val
#     list2=list2.next
#     if list2:
#         temp.next=ListNode()
#         temp=temp.next
    
if carry!=0:
    temp.val=carry

while new:
    print(new.val,end=' ')
    new=new.next




