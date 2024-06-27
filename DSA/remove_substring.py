s='asheaamanojesha'

#remove all a's using recursion 
# def recur3(s,p):
  
#     if len(p)==0:
#         return ''
    
#     if p.startswith("manoj"):
#         return recur3(s,p[5:])
#     else:
#         return p[0]+recur3(s,p[1:])

# p=s
# res=''
# # print(p[1:])
# res=recur3(s,p)
# print(res)

# def recur2(s,p):
#     res=''
#     if len(p)==0:
#         return res
    
#     if p[0]!='a':
#         res+=p[0]

#     res+=recur2(s,p[1:])
#     return res

# p=s
# res=''
# # print(p[1:])
# res=recur2(s,p)
# print(res)

def recur4(s,old,p):

    if len(p)==0:
        return old
    
    if p.startswith("manoj"):
        old+=recur4(s,old,p[5:])
    else:
        old+=p[0]+recur4(s,old,p[1:])
    return old

p=s
res=''
# print(p[1:])
res=recur4(s,res,p)
print(res)