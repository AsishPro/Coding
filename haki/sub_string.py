parent, sub = input(), input()
count = 0

while sub in parent:
    count=count+1
    parent=parent[:parent.find(sub)]+parent[(parent.find(sub)+1):]
    print(parent)
    # print(sub)
    # # i = S.find(sub)
    # # print(S[i + 1:])
    # # S = S[:i] + S[i + 1:]
    # # print(S)

print(count)