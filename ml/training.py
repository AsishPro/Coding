import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split


def find_error(y,yp):
    return abs((y-yp))
    # return abs((y-yp))

def find_pe(y,yp):
    return abs(((y-yp)/y)*100)
    # return (((y-yp)/y)*100)

def find_cfs(df,x):
    # print(x)
    # print()

    y=np.array(df.iloc[:,-1])  #y matrix
    # print(y,end=ln)

    # print(x,end=ln)
    # print(x.T,end=ln)

    product=np.dot(x.T,x)  #x@xT can also be used
    # print(product,end=ln)

    I = np.linalg.inv(product)
    # print(I,end=ln)

    a=np.dot(I,x.T)   # res=I@x.T@y can also be used directly
    a=np.dot(a,y)
    return a





ln="\n\n"

df=pd.read_csv("fish.csv")
# df = pd.read_excel('Multiple.xlsx', sheet_name='Dataset')

df=df.drop('Species',axis=1)
pd.set_option('display.max_rows', None)
pd.set_option('display.max_columns', None)

print(df)
print()

#getting x,y and a matrix
l=[]
n=(len(df.columns))-1
for i in range(len(df)):
    l.append([1,*df.iloc[i,:n]])
x=np.array(l)
a=find_cfs(df,x)
print(a,end=ln)
y=np.array(df.iloc[:,-1])


#YP AND Y
yp=np.dot(x,a)
print(y,end=ln)
print(yp,end=ln)

error=find_error(y,yp)
pe=find_pe(y,yp)

df['error']=error
df['pe']=pe
print(df)
mae=df['error'].sum()/len(df)
mape=df['pe'].sum()/len(df)
print(f"mae and mape are :{mae,mape}, accuaracy: {100-mape}")



# Assuming that `df` contains your DataFrame with the independent and dependent variables
X = df.drop('Width', axis=1) # Independent variables
y = df['Width'] # Dependent variable

# Split the data into training and testing sets
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)
print(f"{X_train}\n{y_train}\n{X_test}\n{y_test}")