import numpy as np
import pandas as pd
from sklearn.model_selection import train_test_split

class GaussianNaiveBayes:
    def fit(self, X, y):
        self.classes = np.unique(y)
        self.prior_probs = {}
        self.feature_params = {}

        # Calculate prior probabilities for each class
        self._calc_prior_probs(y)

        # Calculate mean and variance for each feature in each class
        self._calc_feature_params(X, y)

    def _calc_prior_probs(self, y):
        class_counts = pd.Series(y).value_counts()
        total_samples = len(y)
        for c in self.classes:
            self.prior_probs[c] = class_counts[c] / total_samples

    def _calc_feature_params(self, X, y):
        for c in self.classes:
            class_examples = X[y == c]
            self.feature_params[c] = {}
            for col in X.columns:
                self.feature_params[c][col] = {
                    'mean': class_examples[col].mean(),
                    'variance': class_examples[col].var()
                }

    def _gaussian_likelihood(self, x, mean, variance):
        # Calculate Gaussian likelihood using the probability density function
        exponent = -((x - mean)**2) / (2 * variance)
        likelihood = np.exp(exponent) / np.sqrt(2 * np.pi * variance)
        return likelihood

    def predict(self, X):
        predictions = []

        for _, row in X.iterrows():
            class_scores = {c: np.log(self.prior_probs[c]) for c in self.classes}

            for col in X.columns:
                for c in self.classes:
                    mean = self.feature_params[c][col]['mean']
                    variance = self.feature_params[c][col]['variance']
                    value = row[col]

                    # Calculate the Gaussian likelihood for the feature value in the class
                    likelihood = self._gaussian_likelihood(value, mean, variance)

                    # Update the class score by adding the log-likelihood
                    class_scores[c] += np.log(likelihood)

            # Predict the class label for the current example based on the highest class score
            predicted_class = max(class_scores, key=class_scores.get)
            predictions.append(predicted_class)

        return predictions

# Load the diabetes dataset
url = "https://raw.githubusercontent.com/jbrownlee/Datasets/master/pima-indians-diabetes.data"
column_names = ['Pregnancies', 'Glucose', 'BloodPressure', 'SkinThickness', 'Insulin', 'BMI', 'DiabetesPedigreeFunction', 'Age', 'Outcome']
diabetes_data = pd.read_csv(url, names=column_names)

# Separate features and target variable
X = diabetes_data.drop('Outcome', axis=1)
y = diabetes_data['Outcome']

# Split the data into training and test sets
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Create and train the Gaussian Naive Bayes classifier
gnb = GaussianNaiveBayes()
gnb.fit(X_train, y_train)

# Make predictions on the test set
predictions = gnb.predict(X_test)

# Calculate accuracy
accuracy = np.mean(predictions == y_test)
print("Accuracy:", accuracy)
