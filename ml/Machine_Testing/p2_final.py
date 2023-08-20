import numpy as np
import pandas as pd
from sklearn.preprocessing import MinMaxScaler
import matplotlib.pyplot as plt

def relu(x):
    return np.maximum(0, x)

def relu_derivative(x):
    return (x > 0).astype(int)

df = pd.read_csv("power.csv")
df.head()
X = df.drop("PE", axis=1).values
y = df["PE"].values
print(X.shape[1])
y=y.reshape(-1,1)
scaler_X = MinMaxScaler()

def mse(y_true, y_pred):
    return np.mean((y_pred - y_true) ** 2)

# Define the neural network training function
def train(X, y, hidden_nodes, learning_rate, num_epochs, clip_threshold):
    # Initialize weights and biases
    input_nodes = X.shape[1]
    output_nodes = 1
    w1 = np.random.randn(input_nodes, hidden_nodes)
    b1 = np.ones((1, hidden_nodes))
    w2 = np.random.randn(hidden_nodes, output_nodes)
    b2 = np.ones((1, output_nodes))

    # Scale the input data using MinMaxScaler
    X_scaled = scaler_X.fit_transform(X)
    

    lt=np.array([])
    for epoch in range(num_epochs):
        # Forward pass
        hidden_output = relu(np.dot(X_scaled, w1) + b1)
        final_output = np.dot(hidden_output, w2) + b2

        # Calculate the mean squared error loss
        loss = mse(y, final_output)

        # Backpropagation
        final_error = final_output - y
        hidden_error = final_error.dot(w2.T)
        hidden_delta = hidden_error * relu_derivative(hidden_output)

  
        # Weight and bias updates
        w2 -= learning_rate * hidden_output.T.dot(final_error)
        b2 -= learning_rate * final_error.sum(axis=0, keepdims=True)
        w1 -= learning_rate * X_scaled.T.dot(hidden_delta)
        b1 -= learning_rate * hidden_delta.sum(axis=0, keepdims=True)

        # Print the loss for every 100 epochs
        if epoch % 100 == 0:
            print(f"Epoch {epoch}, Loss: {loss}")
        lt=np.append(lt,loss)
    # print(lt)
    plt.plot(lt)
    plt.show()
    return w1, b1, w2, b2


def predict(w1,b1,w2,b2,X,y):
    # Perform a forward pass through the neural network to get the predictions in the scaled form
        X_scaled = scaler_X.fit_transform(X)
        hidden_output = relu(np.dot(X_scaled, w1) + b1)
        final_output = np.dot(hidden_output, w2) + b2


        # Print the predictions
        print(f"THis is pred: {final_output-y}")
        

# Hyperparameters
hidden_nodes = 10  #6
learning_rate = 0.0000001
num_epochs = 2000
clip_threshold = 5.0


w1,b1,w2,b2 = train(X, y, hidden_nodes, learning_rate, num_epochs, clip_threshold)
predict(w1,b1,w2,b2,X,y)