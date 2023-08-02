import numpy as np
from sklearn.preprocessing import MinMaxScaler

# ... (Previous code)

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
    
    scaler_y = MinMaxScaler()
    y_scaled = scaler_y.fit_transform(y.reshape(-1, 1)).flatten()

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

        # Gradient Clipping
        np.clip(final_error, -clip_threshold, clip_threshold, out=final_error)
        np.clip(hidden_delta, -clip_threshold, clip_threshold, out=hidden_delta)

        # Weight and bias updates
        w2 -= learning_rate * hidden_output.T.dot(final_error)
        b2 -= learning_rate * final_error.sum(axis=0, keepdims=True)
        w1 -= learning_rate * X_scaled.T.dot(hidden_delta)
        b1 -= learning_rate * hidden_delta.sum(axis=0, keepdims=True)

        # Print the loss for every 100 epochs
        if epoch % 100 == 0:
            print(f"Epoch {epoch}, Loss: {loss}")

    return w1, b1, w2, b2

# Example usage with your actual data
# Replace X and y with your actual data
X = np.random.rand(9568, 4)  # Replace this with your actual data
y = np.random.rand(9568, 1)  # Replace this with your actual data

# Hyperparameters
hidden_nodes = 16
learning_rate = 0.01
num_epochs = 1000
clip_threshold = 5.0

# Training the neural network
trained_weights = train(X, y, hidden_nodes, learning_rate, num_epochs, clip_threshold)
