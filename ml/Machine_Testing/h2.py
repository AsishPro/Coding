import numpy as np
import pandas as pd
from sklearn.preprocessing import MinMaxScaler
import matplotlib.pyplot as plt

# Activation function
def relu(x):
    return np.maximum(0, x)

# Derivative of the ReLU activation function
def relu_derivative(x):
    return (x > 0).astype(int)

# Mean squared error loss function
def mse(y_true, y_pred):
    return np.mean((y_pred - y_true) ** 2)

# Define the neural network training function
def train(X, y, hidden_nodes, learning_rate, num_epochs):
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
    scaler_y = MinMaxScaler()
    y_scaled = scaler_y.fit_transform(y)

    lt = np.array([])
    for epoch in range(num_epochs):
        # Forward pass
        hidden_output = relu(np.dot(X_scaled, w1) + b1)
        final_output = np.dot(hidden_output, w2) + b2

        # Calculate the mean squared error loss
        loss = mse(y_scaled, final_output)

        # Backpropagation
        final_error = final_output - y_scaled
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
        lt = np.append(lt, loss)
    plt.plot(lt)
    plt.xlabel('Epoch')
    plt.ylabel('Mean Squared Error Loss')
    plt.show()
    return w1, b1, w2, b2, scaler_X, scaler_y

# Load the house prices dataset
df = pd.read_csv("train.csv")

# Extract features and target variable
features = ['OverallQual' , 'GrLivArea' , 'TotalBsmtSF' , 'BsmtFinSF1' ,
            '2ndFlrSF'    , 'GarageArea', '1stFlrSF'    , 'YearBuilt'  ]
X = df[features].values
y = df["SalePrice"].values.reshape(-1, 1)

# Hyperparameters
hidden_nodes = 10
learning_rate = 0.001
num_epochs = 2000

# Training the neural network
w1, b1, w2, b2, scaler_X, scaler_y = train(X, y, hidden_nodes, learning_rate, num_epochs)

# Make predictions for new data
def predict(X_new, w1, b1, w2, b2, scaler_X, scaler_y):
    X_scaled = scaler_X.transform(X_new)
    hidden_output = relu(np.dot(X_scaled, w1) + b1)
    final_output = np.dot(hidden_output, w2) + b2
    y_pred = scaler_y.inverse_transform(final_output)
    return y_pred.flatten()

# Example: Predict house prices for new data
new_data = X
predicted_prices = predict(new_data, w1, b1, w2, b2, scaler_X, scaler_y)
print("Predicted Prices:", predicted_prices-y)
