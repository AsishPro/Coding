import pandas as pd


def first(d):
    n=len(d)
    print(n)
    # for i in d['TV']:
    #     print(i)
    # for i in d.iloc[:,1]:
    #     print(i)
    # print(d.iloc[:,0])  #returns data series
    # print(*d.iloc[:,0])  #returns values
    # print(d.iloc[:,0].values)  #returns list underlying

    # sum_x=d.iloc[:,0].sum() #all elements in first column
    
    # print(sum_x)
   


df=pd.read_csv("tvmarketing.csv")


b1=first(df)





# for i in range(len(df)):
#     for j in range(len(df.columns)):
#         # compute the product of the element and the scalar value
#         df.iloc[i, j] = df.iloc[i, j] * afor i in range(len(df)):
#     for j in range(len(df.columns)):
#         # compute the product of the element and the scalar value
#         df.iloc[i, j] = df.iloc[i, j] * a



# x=df.iloc[0][1]
# y=list(df['Sales'])


# print(x)


