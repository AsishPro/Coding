import numpy as np
import pandas as pd
from sklearn.preprocessing import MinMaxScaler



def mse(y_true, y_pred):
    return np.mean((y_pred - y_true) ** 2)

def relu(x):
    return 1/(1+np.exp(-x))

def relu_derivative(x):
    return x*(1-x)

def linear(x):
    return x

def linear_derivative(x):
    return np.ones_like(x)

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
    scaler_X = MinMaxScaler()
    X_scaled = scaler_X.fit_transform(X)
    

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

    return 0


# Hyperparameters
hidden_nodes = 6
learning_rate = 0.0001
num_epochs = 500
clip_threshold = 5.0

# Training the neural network
trained_weights = train(X, y, hidden_nodes, learning_rate, num_epochs, clip_threshold)
