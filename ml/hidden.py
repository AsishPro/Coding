import numpy as np

# Define the XOR input and output
X = np.array([[0, 0], [0, 1], [1, 0], [1, 1]])
y = np.array([[0], [1], [1], [0]])
# Define the sigmoid activation function and its derivative
def sigmoid(x):
    return 1 / (1 + np.exp(-x))

def sigmoid_derivative(x):
    return sigmoid(x) * (1 - sigmoid(x))

# Define the neural network architecture
input_dim = 2
hidden_dim = 2
output_dim = 1

# Initialize the weights with random values
W1 = np.random.uniform(low=-1, high=1, size=(input_dim, hidden_dim))
W2 = np.random.uniform(low=-1, high=1, size=(hidden_dim, output_dim))

# Train the network using backpropagation
learning_rate = 0.1
for i in range(10000):
    # Forward pass
    hidden_layer = sigmoid(np.dot(X, W1))
    output_layer = sigmoid(np.dot(hidden_layer, W2))

    # Backward pass
    output_error = y - output_layer
    output_delta = output_error * sigmoid_derivative(output_layer)

    hidden_error = output_delta.dot(W2.T)
    hidden_delta = hidden_error * sigmoid_derivative(hidden_layer)

    # Update weights
    W2 += hidden_layer.T.dot(output_delta) * learning_rate
    W1 += X.T.dot(hidden_delta) * learning_rate

# Make predictions
hidden_layer = sigmoid(np.dot(X, W1))
predictions = sigmoid(np.dot(hidden_layer, W2))
print("Predictions:")
print(predictions)