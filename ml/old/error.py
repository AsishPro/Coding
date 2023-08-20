import pandas as pd
import numpy as np

def find_error(y,yp):
    return abs((y-yp))
    # return abs((y-yp))

def find_pe(y,yp):
    return abs(((y-yp)/y)*100)
    # return (((y-yp)/y)*100)



ln="\n\n"

df=pd.read_csv("fishfull.csv")
# df = pd.read_excel('Multiple.xlsx', sheet_name='Dataset')

df=df.drop('Species',axis=1)
pd.set_option('display.max_rows', None)
pd.set_option('display.max_columns', None)

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
# print(y,end=ln)

# print(x,end=ln)
# print(x.T,end=ln)

product=np.dot(x.T,x)  #x@xT can also be used
# print(product,end=ln)

I = np.linalg.inv(product)
# print(I,end=ln)

a=np.dot(I,x.T)   # res=I@x.T@y can also be used directly
a=np.dot(a,y)
print(a,end=ln)

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
