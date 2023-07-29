import numpy as np

# Define the input and output values for the XOR function
x = np.array([[0,0],[0,1],[1,0],[1,1]])
y = np.array([[0],[1],[1],[0]])

# Define the neural network architecture
input_nodes = 2
hidden_nodes1 = 3
hidden_nodes2 = 3
output_nodes = 1

# Initialize the weights and biases of the neural network
w1 = np.random.uniform(low=-1, high=1, size=(input_nodes, hidden_nodes1))
w2 = np.random.uniform(low=-1, high=1, size=(hidden_nodes1, hidden_nodes2))
w3 = np.random.uniform(low=-1, high=1, size=(hidden_nodes2, output_nodes))

b1 = np.random.uniform(low=-1, high=1, size=(1, hidden_nodes1))
b2 = np.random.uniform(low=-1, high=1, size=(1, hidden_nodes2))
b3 = np.random.uniform(low=-1, high=1, size=(1, output_nodes))

# Define the activation function (sigmoid in this case)
def sigmoid(x):
    return 1 / (1 + np.exp(-x))

# Train the neural network using backpropagation
learning_rate = 0.1
for i in range(10000):
    # Forward propagation
    hidden_output1 = sigmoid(np.dot(x, w1) + b1)
    hidden_output2 = sigmoid(np.dot(hidden_output1, w2) + b2)
    final_output = sigmoid(np.dot(hidden_output2, w3) + b3)

    # Calculate the error
    error = y - final_output

    # Backpropagation
    derivative_output = final_output * (1 - final_output) * error
    derivative_hidden2 = hidden_output2 * (1 - hidden_output2) * np.dot(derivative_output, w3.T)
    derivative_hidden1 = hidden_output1 * (1 - hidden_output1) * np.dot(derivative_hidden2, w2.T)

    # Update the weights and biases
    w3 += learning_rate * np.dot(hidden_output2.T, derivative_output)
    w2 += learning_rate * np.dot(hidden_output1.T, derivative_hidden2)
    w1 += learning_rate * np.dot(x.T, derivative_hidden1)

    b3 += learning_rate * np.sum(derivative_output, axis=0)
    b2 += learning_rate * np.sum(derivative_hidden2, axis=0)
    b1 += learning_rate * np.sum(derivative_hidden1, axis=0)

# Test the neural network on the input values
test_input = np.array([[0,1],[1,1],[1,1],[1,1]])
test_output = sigmoid(np.dot(sigmoid(np.dot(sigmoid(np.dot(test_input, w1) + b1), w2) + b2), w3) + b3)

print(np.round(test_output))

