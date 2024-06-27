# def paths(p,i,j,m,n):
#     lt=[]
#     if i==m-1 or j==n-1:
        
#         if i==m-1:
#             p+='R'*(n-j-1)
#         else:
#             p+='D'*(m-i-1)
#         # print(p)
#         lt.append(p)
#         return lt
#     lt+=paths(p+'D',i+1,j,m,n)
#     lt+=paths(p+'R',i,j+1,m,n)
#     return lt


#passing lt
def paths(lt,p,i,j,m,n):
    if i==m-1 or j==n-1:
        if i==m-1:
            p+='R'*(n-j-1)
        else:
            p+='D'*(m-i-1)
        # print(p)
        lt.append(p)
        return 
    paths(lt,p+'D',i+1,j,m,n)
    paths(lt,p+'R',i,j+1,m,n)
    

m=3
n=4
p=''
lt=[]
print(paths(lt,p,0,0,m,n))
print(lt)


