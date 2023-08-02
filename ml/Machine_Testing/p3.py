# Assuming you have already trained the neural network and obtained the trained weights (w1, b1, w2, b2)

# Load new data for prediction (replace 'new_data.csv' with the path to your new data file)
new_data = pd.read_csv("new_data.csv")
X_new = new_data.values

# Scale the new data using the same scaler used during training
X_new_scaled = scaler_X.transform(X_new)

# Perform a forward pass through the neural network to get the predictions in the scaled form
hidden_output = relu(np.dot(X_new_scaled, w1) + b1)
final_output = np.dot(hidden_output, w2) + b2

# Inverse transform the scaled predictions to get predictions in the original scale
y_pred_scaled = final_output
y_pred = scaler_y.inverse_transform(y_pred_scaled)

# Print the predictions
print(y_pred)
