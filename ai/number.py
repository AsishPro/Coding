from sklearn.model_selection import RandomizedSearchCV
import numpy as np

# Define the hyperparameter space you want to search
param_dist = {
    'learning_rate': [0.001, 0.01, 0.1],
    'hidden_layer_sizes': [(9, 1), (12, 4), (18, 5)],
    'activation': ['relu', 'tanh'],
    'max_iter': [1000],
}

ann_classifier = NeuralNetwork(input_size=x_train.shape[1], hidden_nodes=[12,4], output_size=1)


random_search = RandomizedSearchCV(
    ann_classifier,
    param_distributions=param_dist,
    n_iter=10, 
    scoring='accuracy', 
    cv=5, 
    random_state=42
)

random_search.fit(x_train, y_train)

best_params = random_search.best_params_
best_model = random_search.best_estimator_

predictions = best_model.predict(x_test)


accuracy = np.mean(predictions == y_test)
print(f"Best ANN Accuracy: {accuracy * 100:.2f}%")
print("Best Hyperparameters:", best_params)
