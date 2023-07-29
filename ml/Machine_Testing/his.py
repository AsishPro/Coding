import numpy as np

# Define the activation function (sigmoid)
def sigmoid(x):
    return 1 / (1 + np.exp(-x))

# Define the derivative of the sigmoid function
def sigmoid_derivative(x):
    return sigmoid(x) * (1 - sigmoid(x))

# Define the neural network class
class NeuralNetwork:
    def __init__(self, learning_rate=0.1):
        # Define the network architecture
        self.input_size = 2
        self.hidden_size = 4
        self.output_size = 1
        
        # Initialize the weights with random values
        self.weights1 = np.array([[0.1,0.2,0.3,0.1],[0.2,0.2,0.6,0.2]])
        self.weights2 = np.array([[0.3],[0.1],[0.4],[0.2]])
        
        # Initialize the biases with random values
        self.bias1 = np.array([[0.1,0.2,0.3,0.4]])
        self.bias2 = np.array([[0.1]])
        
        # Set the learning rate
        self.learning_rate = learning_rate
        
    def forward(self, X):
        # Perform forward propagation
        self.z1 = np.dot(X, self.weights1) + self.bias1
        self.a1 = sigmoid(self.z1)
        self.z2 = np.dot(self.a1, self.weights2) + self.bias2
        self.output = sigmoid(self.z2)
        
        return self.output
    
    def backward(self, X, y, output):
        # Perform backward propagation
        self.error = y - output
        self.delta_output = self.error * sigmoid_derivative(self.z2)
        self.error_hidden = np.dot(self.delta_output, self.weights2.T)
        self.delta_hidden = self.error_hidden * sigmoid_derivative(self.z1)
        
        # Update the weights and biases with learning rate
        self.weights2 += self.learning_rate * np.dot(self.a1.T, self.delta_output)
        self.weights1 += self.learning_rate * np.dot(X.T, self.delta_hidden)
        self.bias2 += self.learning_rate * np.sum(self.delta_output, axis=0)
        self.bias1 += self.learning_rate * np.sum(self.delta_hidden, axis=0)
        
    def train(self, X, y, epochs):
        for epoch in range(epochs):
            output = self.forward(X)
            self.backward(X, y, output)
            
    def predict(self, X):
        output = self.forward(X)
        predictions = output
        return predictions
    def printt(self):
        print(w)
# Training data (AND gate truth table)
X = np.array([[0, 0],
              [0, 1],
              [1, 0],
              [1, 1]])

y = np.array([[0],
              [1],
              [1],
              [0]])

# Create and train the neural network
nn = NeuralNetwork(learning_rate=0.1)
nn.train(X, y, epochs=1000)

# Test the neural network
test_data = np.array([[0, 0],
                      [0, 1],
                      [1, 0],
                      [1, 1]])

predictions = nn.predict(test_data)

# Print the predictions
for i in range(len(test_data)):
    input_data = test_data[i]
    prediction = predictions[i][0]
    print(f"Input: {input_data}  Prediction: {prediction}")
