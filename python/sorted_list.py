# You are using Python
n=int(input())
list_1=[int(n) for n in input().split()]
search=int(input())
if search in list_1:
    print("The element is present in the list")
else:
    print("The element is not present in the list")
list_2=tuple(list_1)
print("The elements in the tuple are: ",list_2)
print("The sorted elements of the tuple are:",(sorted(list_1)))