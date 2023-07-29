# import numpy as np

# a=np.array([[0,1],[1,0]])
# b=np.array([[0.1,0.2,0.3,0.4],[1,2,3,4]])
# print(a@b)

def atoi(str):
    temp=""
    for i in str:
        try:
            if(int(i) or i=="-"):
                temp+=i
        except:
            pass
    return temp

print(atoi("app546er"))
