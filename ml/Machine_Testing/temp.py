import numpy as np


def act(x):
    return 1/(1+np.exp(-x))
def bound(x):
    return np.clip(x,-1,1)

x=np.array([[0,0],[0,1],[1,0],[1,1]])
y=np.array([[0],[1],[1],[0]])


input_nodes=2
hidden_nodes=2
output_nodes=1

w1=np.random.uniform(low=-1,high=1,size=(input_nodes,hidden_nodes))
w2=np.random.uniform(low=-1,high=1,size=(hidden_nodes,output_nodes))

b1=np.random.uniform(low=-1,high=1,size=(1,hidden_nodes))
b2=np.random.uniform(low=-1,high=1,size=(1,output_nodes))

print(w1)
print(w2)
print(b1)
print(b2)


me=0
mae=0
index=0      # for output (y) 
l=0.1
el=np.array([])

for i in range(1000):
    me=0
    mae=0
    for i in x:   
        hidden_output=act(i@w1+b1)  # 1x2
        final_output=act(hidden_output@w2+b2) #1x1

        #w2= 2x1
        final_error=final_output*(1-final_output)*(y[index]-final_output) #1x1  
        hidden_error=hidden_output*(1-hidden_output)*(final_error@w2.T) #should be 1x2 #print((w2@final_error).T) also works

        me+=final_error
        
        #w1 2x2
        #i 1x2
        w2=w2+(l*(hidden_output.T@final_error))

        #print(hidden_error.T@i.reshape(1,2))
        #print(i.reshape(1,2).T@hidden_error)

        w1=w1+(l*(i.reshape(1,2).T@hidden_error))

        b2=b2+(l*final_error)
        b1=b1+(l*hidden_error)

        index=(index+1)%4
        
    me=me/4
    el=np.append(el,me)
print(el)
    
    

def output(i):
    hidden_output=act(i@w1+b1)  # 1x2
    final_output=act(hidden_output@w2+b2)
    return final_output

k=np.array([0,0])
print(output(k))
k=np.array([1,0])
print(output(k))
k=np.array([0,1])
print(output(k))
k=np.array([1,1])
print(output(k))

test=np.array([[1,1],[0,0],[1,0],[0,1],[0,0]])
for i in test:
  print(np.round(output(i)))