import numpy as np

def act(x):
    return 1/(1+ np.exp(-x))
def derivative(x):
    return x*(1-x)

x=np.array([[0,0],[0,1],[1,0],[1,1]])
y=np.array([[0],[1],[1],[0]])

i_n=2
h_n=4
h_o=1

w1=np.array([[0.1,0.2,0.3,0.1],[0.2,0.2,0.6,0.2]])
w2=np.array([[0.3],[0.1],[0.4],[0.2]])

b1=np.array([[0.1,0.2,0.3,0.4]])
b2=np.array([[0.1]])


l=0.1
for j in range(1000):
    for i in range(len(x)):
        t=y[i]
        i=x[i].reshape(1,2)

        # i - 1x2 w1 2x4 o = 1x4 
        h=np.dot(i,w1)+b1
        hidden_o=act(np.dot(i,w1)+b1) #1x4
        f=np.dot(hidden_o,w2)+b2
        final_o=act(np.dot(hidden_o,w2)+b2) #1x1
    #     print(final_o)


        final_e=derivative(final_o)*(t-final_o) #1x1
        hidden_e=derivative(hidden_o)*(final_e@w2.T)  #should be 1x4

        #final_e 1x1 and hidden_o is 1x4
        #i is 1x2 and hidden_e is 1x4
        w2+=l*(hidden_o.T@final_e)   #should be 4x1
        w1+=l*(i.T@hidden_e)         #should be 2x4


        b2+=l*(final_e)
        b1+=l*(hidden_e)    


def predict(x):
    hidden_o=act(np.dot(i,w1)+b1) #1x4
    final_o=act(np.dot(hidden_o,w2)+b2)
    return np.round(final_o)


test=x
for i in test:
    print(predict(i))