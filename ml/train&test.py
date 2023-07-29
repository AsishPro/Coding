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

    product= np.dot(x.T,x)  #x@xT can also be used
    # print(product,end=ln)

    I = np.linalg.inv(product)
    # print(I,end=ln)

    a=np.dot(I,x.T)   # res=I@x.T@y can also be used directly
    a=np.dot(a,y)
    return a

def split(df):
    l=[]
    n=(len(df.columns))-1
    for i in range(len(df)):
        l.append([1,*df.iloc[i,:n]]) #can also use df.iloc[i,:-1]
    x=np.array(l)
    return x

def routine(df):
    #getting x,y and a matrix
    x=split(df)
    print(x)

    a=find_cfs(df,x)
    print(a,end=ln)
    y=np.array(df.iloc[:,-1])
    testing(df,x,y,a)
    return a

def testing(df,x,y,a):
    #YP AND Y
    yp=np.dot(x,a)
    # print(y,end=ln)
    # print(yp,end=ln)
    error=find_error(y,yp)
    pe=find_pe(y,yp)
    df['error']=error
    df['pe']=pe



ln="\n\n"

total=pd.read_csv("fish.csv")
# df = pd.read_excel('Multiple.xlsx', sheet_name='Dataset')

total=total.drop('Species',axis=1)
pd.set_option('display.max_rows', None)
pd.set_option('display.max_columns', None)


print()

df,test = train_test_split(total, test_size=0.2, random_state=42)
print(f"train:\n{df}\n\ntest:\n{test}\n\n")

a=routine(df)
print(df)
mae=df['error'].sum()/len(df)
mape=df['pe'].sum()/len(df)
print(f"\nmae and mape are :{mae,mape}, accuaracy: {100-mape}\n\n")


x2=split(test)
y2=np.array(test.iloc[:,-1])
testing(test,x2,y2,a)
print(test,end="\n\n")
mae=test['error'].sum()/len(test)
mape=test['pe'].sum()/len(test)
print(f"\nmae and mape are :{mae,mape}, accuaracy: {100-mape}\n\n")





