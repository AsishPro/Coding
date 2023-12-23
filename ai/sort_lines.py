import re
def find(words):
    # res=words.split(" ")
    # res= [word.split('.\n') for word in res]
    res=re.findall(r'\b\w+|\.', words)
    print(res)
    return res

lt=[]
f=open("t2.txt",'r')
l=0
for i in f:
    l+=1
    lt.append(find(i))
f.close()