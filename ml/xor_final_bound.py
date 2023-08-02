import numpy as np

x=np.array([[0,0],[0,1],[1,0],[1,1]])
y=np.array([[0],[1],[1],[0]])


input_nodes=2
hidden_nodes=4
output_nodes=1

w1=np.random.uniform(low=-1,high=1,size=(input_nodes,hidden_nodes))
w2=np.random.uniform(low=-1,high=1,size=(hidden_nodes,output_nodes))

b1=np.random.uniform(low=-1,high=1,size=(1,hidden_nodes))
b2=np.random.uniform(low=-1,high=1,size=(1,output_nodes))


def act(x):
    return 1/(1+np.exp(-x))
def bound(x):
    return np.clip(x,-1,1)

me=0
index=0      # for output (y)
l=0.1
lme=np.array([])
for k in range(10000):
    for i in x:
        hidden_output=act(i@w1+b1)  #1x2
        final_output=act(hidden_output@w2+b2) #1x1

        final_error=final_output*(1-final_output)*(y[index]-final_output)
        me+=final_error

        hidden_error=hidden_output*(1-hidden_output)*(final_error@w2.T)

        w2=bound(w2+(l*(hidden_output.T@final_error)))
        w1=bound(w1+(l*np.outer(i,hidden_error)))

        b2=bound(b2+(l*final_error))
        b1=bound(b1+(l*hidden_error))

        index=(index+1)%4
    mae=me/4
    lme=np.append(lme,mae)



def output(i):
    hidden_output=act(i@w1+b1)  #1x2
    final_output=act(hidden_output@w2+b2) #1x1
    return final_output

#add more hidden layers or more nodes in one hidden layer
#why output for 1,1 is greater than all others ????

test=np.array([[0,0],[0,1],[1,0],[1,1]])
for i in test:
  print(np.round(output(i)))