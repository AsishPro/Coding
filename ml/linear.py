import pandas as pd


def first(d):
    n=len(d)
    print(n)
    x=d.iloc[:,0].values #all elements in first column
    y=d.iloc[:,1].values #all elements in second column
    sum_x=x.sum() 
    sum_y=y.sum() 
    mean_x=sum_x/n
    mean_y=sum_y/n

    sq = list(map(lambda x:x**2,x))
    # sq=x**2
    # print(x_sq)
    d['x_sq']=sq  #giving new column
    sum_sq=d.iloc[:,2].sum() 

    d['xy']=list(map(lambda a,b:a*b,x,y))
    sum_xy=d['xy'].sum()
    # print(sum_xy)
      
    # print(d)

    b1=((n*sum_xy)-(sum_x*sum_y))/((n*sum_sq)-(sum_x)**2) #slope
    print(f"b1 slope :{b1}")
    b0=mean_y-b1*mean_x
    print(f"b0 offset :{b0}")

    
    
    # print(sum_x)
   


df=pd.read_csv("tvmarketing.csv")

# print(df)
b1=first(df)









# x=df.iloc[0][1]
# y=list(df['Sales'])


# print(x)


