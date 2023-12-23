import numpy as np
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import roc_curve, auc

# Generate synthetic data
np.random.seed(42)
X = np.random.rand(1000, 10)  # 10 features for each sample
y = (X.sum(axis=1) > 5).astype(int)  # Target variable: 1 if sum of features > 5, else 0

# Split the data into training and testing sets
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3, random_state=42)

# Train a classifier (Random Forest for this example)
clf = RandomForestClassifier(random_state=42)
clf.fit(X_train, y_train)

# Get predicted probabilities on the test set
probs = clf.predict_proba(X_test)[:, 1]  # Probability of class 1

# Calculate ROC curve and AUC
fpr, tpr, _ = roc_curve(y_test, probs)
roc_auc = auc(fpr, tpr)

# Calculate lift chart values
percentile = np.linspace(0, 100, len(y_test))
percentile_index = np.percentile(percentile, np.arange(0, 101, 10))
lift_values = []

for p in percentile_index:
    threshold = np.percentile(probs, 100 - p)
    lift_values.append(np.sum(y_test[probs >= threshold]) / np.sum(y_test))

# Plot ROC curve
plt.figure(figsize=(8, 6))
plt.plot(fpr, tpr, color='b', lw=2, label=f'ROC Curve (AUC = {roc_auc:.2f})')
plt.plot([0, 1], [0, 1], color='gray', linestyle='--')
plt.xlabel('False Positive Rate')
plt.ylabel('True Positive Rate')
plt.title('Receiver Operating Characteristic (ROC) Curve')
plt.legend(loc='lower right')

# Plot Lift Chart
plt.figure(figsize=(8, 6))
plt.plot(percentile_index, lift_values, marker='o', color='r', label='Lift Chart')
plt.xlabel('Percentage of Data')
plt.ylabel('Lift')
plt.title('Lift Chart')
plt.legend(loc='upper left')

plt.show()
