lst=input().split()
print(lst)

# k=lst.split()
# print(k)
sum=0
for i in lst:
    try:
        sum+=float(i)
    except:
        pass

print(sum)