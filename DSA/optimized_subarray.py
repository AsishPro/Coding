def recur(l, start, end, temp_str):
    if start == len(l):
        return
    
    if end == len(l):
        recur(l, start + 1, start + 1, "")
        return
    
    temp_str += str(l[end])
    print(temp_str)
    recur(l, start, end + 1, temp_str)

l = [1, 2, 3, 4, 5]
recur(l, 0, 0, "")



# l=[1,2,3,4,5]


# for i in range(len(l)):
#     temp=''
#     for j in range(i,len(l)):
#         temp+=str(l[j])
#         print(temp)

