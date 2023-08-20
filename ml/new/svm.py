from sklearn.svm import SVC
svm = SVC(kernel='linear', random_state=42)
svm.fit
y_pred = svm.predict(x_test)
