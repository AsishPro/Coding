import pandas as pd
import numpy as np

ln="\n\n"
# a = df.iloc[:, 0].to_numpy()
# b = df.iloc[:, 1].to_numpy()

# # Stack the two arrays horizontally to create a single matrix
# matrix = np.stack((a, b), axis=1)

# # Print the resulting matrix
# print("Matrix:\n", matrix)

df=pd.read_csv("tvmarketing.csv")
# df = pd.read_excel('Multiple.xlsx', sheet_name='Dataset')

print(df)
print()

#getting x matrix
l=[]
n=(len(df.columns))-1
for i in range(len(df)):
   l.append([1,*df.iloc[i,:n]])
x=np.array(l)
# print(x)
# print()

y=np.array(df.iloc[:,-1])  #y matrix
print(y,end=ln)

print(x,end=ln)
print(x.T,end=ln)

product=np.dot(x.T,x)  #x@xT can also be used
print(product,end=ln)

I = np.linalg.inv(product)
print(I,end=ln)

res=np.dot(I,x.T)   # res=I@x.T@y can also be used directly
res=np.dot(res,y)
print(res)

