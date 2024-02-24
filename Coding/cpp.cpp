// You are using GCC
#include<iostream>
using namespace std;
int size;
class matrix
{
    public:
    int arr[100][100];
    int i=0,j=0;
    void getdata()
    { 
        for (int i=0;i<size;i++)
        {
            for(int j=0;j<size;j++)
            {
            cin>>arr[i][j];
        }
        }
    }
    void display()
    {
        int i=0,j=0;
        for(i=0;i<size;i++)
        {
            for(j=0;j<size;j++)
            {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
        }
    }
    friend matrix operator+(matrix&m,matrix&m1);
    friend matrix operator*(matrix&m,matrix&m1);
      
};

matrix operator+(matrix&m,matrix&m1)
{
    int i=0,j=0;
    matrix temp;
    for(i=0;i<size;i++)
    {   
        for(j=0;j<size;j++)
        {
            temp.arr[i][j]=m1.arr[i][j]+m.arr[i][j];
        }
    }
    return temp;
}

matrix operator*(matrix&m,matrix&m1)
{
    int i=0,j=0;
    matrix temp;
    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
            for(int k=0;k<size;k++)
            {
                  temp.arr[i][j] += m.arr[i][k] * m1.arr[k][j];
            }
        }
    }
    return temp;
}
bool operator==(matrix&m,matrix&m1)
{
    int i=0,j=0;
    matrix temp;
    for(i=0;i<size;i++)
    {   
        for(j=0;j<size;j++)
        {
            if(m1.arr[i][j]!=m.arr[i][j])
               return false;
        }
    }
    return true;
}

int main()
{
    cin>>size;
    matrix m1,m2;
    m1.getdata();
    m2.getdata();
    matrix m3;
    m3=m1+m2;
    m3.display();
    matrix m4;
    m4=m1*m2;
    m4.display();
    
    bool z=(m1==m2);
    if(z)
    cout<<"Both are same"<<endl;
    else
    cout<<"Both are not same"<<endl;
}