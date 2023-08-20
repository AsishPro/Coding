import numpy as np
import pandas as pd
from sklearn.preprocessing import MinMaxScaler
import matplotlib.pyplot as plt

def act(x):
    return np.maximum(0,x)
def derivative(x):
    return (x > 0).astype(int)  
    # return x*(1-x)
df = pd.read_csv("power.csv")
df.head()
x = df.drop("PE", axis=1).values
y = df["PE"].values
y=y.reshape(-1,1)


i_n=x.shape[1]
h_n=10
h_o=1

w1 = np.random.randn(i_n, h_n)
b1 = np.ones((1, h_n))
w2 = np.random.randn(h_n, h_o)
b2 = np.ones((1, h_o))

l= 0.0000001
error=0
lt=np.array([])
epoch=10
scaler_X = MinMaxScaler()
t=y 
i = scaler_X.fit_transform(x)
for j in range(epoch):
       

        hidden_o=act((i@w1)+b1) #1x4
        final_o=(hidden_o@w2)+b2#1x1
        #print(final_o)
        error=np.mean((t - final_o) ** 2)


        final_e=final_o-t #1x1
        # final_e=-(y-final_o)
        hidden_e=(final_e@w2.T)*derivative(hidden_o)  #should be 1x4

        #final_e 1x1 and hidden_o is 1x4
        #i is 1x2 and hidden_e is 1x4
        w2-=l*(hidden_o.T@final_e)   #should be 4x1
        w1-=l*(i.T@hidden_e)         #should be 2x4

        print(b2-l*np.sum(hidden_e))
        print(b2-l*hidden_e.sum(axis=0, keepdims=True))   #take this one
        print()
        b2-=l*np.sum(final_e)

        b1-=l*np.sum(hidden_e)
        # if j % 100 == 0:
        #     print(f"Epoch {j}, Loss: {error}")
        lt=np.append(lt,error)
plt.plot(lt)
plt.show()



# def predict(x):
#     hidden_o=act(x@w1+b1)
#     final_o=act(hidden_o@w2+b2)
#     return final_o


# test=x
# for i in test:
#     print(predict(i))

# test=x
# for i in test:
#     print(np.round(predict(i)))



