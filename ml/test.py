import numpy as np
import pandas as pd
from sklearn.datasets import load_iris
from sklearn.preprocessing import MinMaxScaler
from sklearn.model_selection import train_test_split
from sklearn.svm import SVC
from sklearn.metrics import accuracy_score

def act(x):
    return np.maximum(0, x)   # ReLU activation

def derivative(x):
    return (x > 0).astype(int)

def sigmoid(x):
    return 1 / (1 + np.exp(-x))


df = pd.read_csv("diabetes.csv")
x = df.drop("Outcome", axis=1).values
y = df["Outcome"].values
# iris = load_iris()
# X, y = iris.data, iris.target

x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=0.8, random_state=42)

i_n = x.shape[1]
h_n = 32
output_classes = 1  # Binary classification

w1 = np.random.randn(i_n, h_n)
b1 = np.ones((1, h_n))
w2 = np.random.randn(h_n, output_classes)
b2 = np.ones((1, output_classes))

l = 0.001
error = 0
lt = np.array([])
epoch = 1000
scaler_X = MinMaxScaler()
t = y_train.reshape(-1, 1)  # Reshape y to match output shape
i = scaler_X.fit_transform(x_train)
k = scaler_X.transform(x_test)

for j in range(epoch):
    hidden_o = act((i @ w1) + b1)
    final_o = sigmoid((hidden_o @ w2) + b2)  # Apply sigmoid activation
    error=np.mean((t - final_o) ** 2)
    final_e = final_o - t
    hidden_e = (final_e @ w2.T) * derivative(hidden_o)

    w2 -= l * (hidden_o.T @ final_e)
    w1 -= l * (i.T @ hidden_e)

    b2 -= l * final_e.sum(axis=0, keepdims=True)
    b1 -= l * hidden_e.sum(axis=0, keepdims=True)

    if j % 100 == 0:
        print(f"Epoch {j}, Loss: {error}")
    lt = np.append(lt, error)

def predict(x):
    hidden_o = act(x @ w1 + b1)
    return hidden_o @ w2 + b2  # Apply sigmoid activation

# Extract features from the last hidden layer for training and testing data
train_hidden_o = act(x_train @ w1 + b1)
train_features = train_hidden_o @ w2 + b2  # No sigmoid activation

test_hidden_o = act(x_test @ w1 + b1)
test_features = test_hidden_o @ w2 + b2  # No sigmoid activation

# Train an SVM classifier using the extracted features
svm_classifier = SVC(kernel='linear')
svm_classifier.fit(train_features, y_train)

# Predict using the trained SVM classifier
svm_predictions = svm_classifier.predict(test_features)

nn_predictions = predict(k)
nn_binary_predictions = (nn_predictions >= 0.5).astype(int)
nn_accuracy = accuracy_score(y_test, nn_binary_predictions)
print(f"Neural Network Accuracy: {nn_accuracy}")

# Evaluate SVM accuracy
svm_accuracy = accuracy_score(y_test, svm_predictions)
print(f"SVM Accuracy: {svm_accuracy}")