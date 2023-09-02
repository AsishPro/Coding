import pandas as pd
import numpy as np

c=['Sample code number','Clump Thickness','Uniformity of Cell Size','Uniformity of Cell Shape','Marginal Adhesion','Single Epithelial Cell Size','Bare Nuclei','Bland Chromatin','Bland Chromatin','Bland Chromatin','Class']
df=pd.read_csv("breast-cancer-wisconsin.data")
df.columns=c
df

df.drop('Sample code number',axis=1,inplace=True)
df.drop(df[df['Bare Nuclei'] == '?'].index, inplace=True)
df['Bare Nuclei'] = df['Bare Nuclei'].astype(int)
df['Class']=np.where(df["Class"]==2,-1,1)


x=df.drop('Class',axis=1).values
y=df['Class'].values

from sklearn.model_selection import train_test_split


x_train, x_test, y_train, y_test = train_test_split(x, y, test_size = 0.7, random_state = 42)

import numpy as np
from sklearn import svm

clf= svm.SVC(kernel='rbf', random_state=1, gamma=0.008, C=0.1)

# Train the classifier
clf.fit(x_train, y_train)

# Test point: (1, 2)
p = clf.predict(x_test)

accuracy = np.mean(p == y_test)
print(accuracy)