import numpy as np


def activation(x):
    return 1/(1+np.exp(-x))

def output(x):
     return np.clip(x,-1,1)

x=np.array([[0,0],[0,1],[1,0],[1,1]])
y=np.array([[0],[1],[1],[0]])
# print(x@y)

input_n=2
hidden_n=2
output_n=1

# w1=np.array([[1,1],[1,1]])
# w2=np.array([[1],[1]])

w1=np.random.uniform(low=-1,high=1,size=(input_n,hidden_n))
temp1=w1
w2=np.random.uniform(low=-1,high=1,size=(hidden_n,output_n))
temp2=w2
print("initial")
print(w1)
print(w2,end="\n\n")

# b1=np.array([1,2])
# b2=np.array([[1]])
b1=np.random.uniform(low=-1,high=1,size=(len(x),hidden_n))
btemp1=b1
print("old bias")
print(b1)
b2=np.random.uniform(low=-1,high=1,size=(len(x),output_n))
btemp2=b2
print(b2,end="\n\n\n")

for i in range(100):
        I1=x.dot(w1)+b1
        o_hidden=activation(I1) #hidden layer output
        # print()
        # print(o_hidden)
        o_out=activation(o_hidden.dot(w2)+b2) #final output or
        # print(o_out,end="\n\n")

        # error of output layer
        o_error=o_out*(1-o_out)*(y-o_out)
        # print(o_error)

        #error of hidden layer
        h_error=o_hidden*(1-o_hidden)*(o_error@w2.T)
        # print(h_error,end="\n\n\n")
        l=0.9
        w2=output(w2+(l*o_hidden.T@o_error))
        w1=output(w1+(l*x.T@h_error))
        # print(w2)

        b2=output(b2+(l*o_error))
        b1=output(b1+(l*h_error))


print("New weight")
print(w1,end="\n")
print(w2,end="\n\n\n")
print("New Bias")
print(b1,end="\n")
print(b2,end="\n\n\n")

I1=x.dot(w1)+b1
o_hidden=activation(I1) #hidden layer output
# print(o_hidden)
o_out=activation(o_hidden.dot(w2)+b2) #final output or
print(o_out,end=" is final output\n\n")


# errr=y-o_out
# min=50
# index=0
# for i in range(len(y)):
#       print(i,errr[i])
#       if(errr[i]<min):
#             min=errr[i]
#             index=i

# print(index,end="\n\n")


print("input testing")
x1=np.array([[1,1],[1,1],[1,1],[1,1]])
I1=x1@w1+b1
o_hidden=activation(I1) #hidden layer output
        # print()
        # print(o_hidden)
o_out=activation(o_hidden.dot(w2)+b2) #final output or
print(o_out,end="output \n\n")
 



