import pandas as pd
import numpy as np


# # print()

# a = df.iloc[:, 0].to_numpy()
# b = df.iloc[:, 1].to_numpy()

# # Stack the two arrays horizontally to create a single matrix
# matrix = np.stack((a, b), axis=1)

# # Print the resulting matrix
# print("Matrix:\n", matrix)

df=pd.read_csv("tvlist.csv")

print(df)
print()

#getting x matrix
l=[]
n=(len(df.columns))-1
for i in range(len(df)):
   l.append([1,*df.iloc[i,:n]])
print(l)
x=np.array(l)
# print(x)
# print(x)
# print()

y=np.array(df.iloc[:,-1])  #y matrix
# print(y,end="\n\n")


print(x)
print(x.T)
print()
product=np.dot(x.T,x)  #x@xT can also be used
print(product)
I = np.linalg.inv(product)
print(I)
print()
res=np.dot(I,x.T)
res=np.dot(res,y)
print(res)


# k=d.iloc[:,0].values.T
# print(k)
# print(d)
# z=np.dot(d.iloc[:,0].values,d.iloc[:,1].values)
# print(z)




