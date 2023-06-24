import numpy as np


def output(x):
    return 1/(1+np.exp(-x))
x=np.array([[0,0],[0,1],[1,0],[1,1]])
y=np.array([[0],[1],[1],[0]])
# print(x@y)

input_n=2
hidden_n=3
output_n=1

w1=np.array([[1,1],[1,1]])
# w1=np.random.uniform(low=-1,high=1,size=(input_n,hidden_n))
w2=np.random.uniform(low=-1,high=1,size=(hidden_n,output_n))

b1=np.random.uniform(low=-1,high=1,size=(1,hidden_n))
b2=np.random.uniform(low=-1,high=1,size=(1,output_n))
# print(w1)
print(b1,end="\n\n")
print(x.dot(w1))

I1=x.dot(w1)+b1
print(I1)
o_hidden=output(I1) #hidden layer output
o_out=output(o_hidden.dot(w2)+b2) #final output or

# error of output layer
o_error=o_out*(1-o_out)*(y-o_out)  #element wize because (doubt)

#error of hidden layer 

