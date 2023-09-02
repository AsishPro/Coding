import numpy as np
import pandas as pd
from sklearn.preprocessing import MinMaxScaler
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split


def act(x):
    return np.maximum(0,x)   #relu
def derivative(x):
    return (x > 0).astype(int)    #relu derivate
    # return x*(1-x)


df = pd.read_csv(".csv")
df.head()
x = df.drop("PE", axis=1).values
y = df["PE"].values
y=y.reshape(-1,1)

x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=0.2, random_state=42)


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
epoch=2000
scaler_X = MinMaxScaler()
t=y_train 
i = scaler_X.fit_transform(x_train)

for j in range(epoch):
       
        hidden_o=act((i@w1)+b1) 
        final_o=(hidden_o@w2)+b2
        error=np.mean((t - final_o) ** 2)


        final_e=final_o-t 
        hidden_e=(final_e@w2.T)*derivative(hidden_o)  

      
        w2-=l*(hidden_o.T@final_e)  
        w1-=l*(i.T@hidden_e)        

        # print(b2-l*np.sum(hidden_e))   losses more with this
        # print(b2-l*hidden_e.sum(axis=0, keepdims=True))   take this one

        b2-=l*final_e.sum(axis=0, keepdims=True)
        b1-=l*hidden_e.sum(axis=0, keepdims=True)

        if j % 100 == 0:
            print(f"Epoch {j}, Loss: {error}")
        lt=np.append(lt,error)
plt.plot(lt)
plt.show()



def predict(x,y):
    hidden_o=act(x@w1+b1)
    final_o=hidden_o@w2+b2
    return np.mean((final_o-y)**2)


test_input = scaler_X.transform(x_test)
test_loss = predict(test_input, y_test)
print(f"Loss on the testing dataset: {test_loss}")
