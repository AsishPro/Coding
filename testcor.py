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

    subx = list(map(lambda x:x-mean_x,x))

    suby = list(map(lambda y:y-mean_y,y))

    d['mul']=list(map(lambda a,b:a*b,subx,suby))
    sum_mul=d['mul'].sum()
    # print(sum_xy)
   
    sq = list(map(lambda x:x**2,subx))
    # print(x_sq)
    d['sub_sq']=sq  #giving new column
    sum_sq=d.iloc[:,3].sum() 


    b1=sum_mul/sum_sq
    print(d)
    print()
    print(b1)



df=pd.read_csv("tvmarketing.csv")
# df = pd.read_excel('test.xlsx', sheet_name='Example #2')
ans=first(df)




