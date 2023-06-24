#include <iostream>
#include <math.h>
using namespace std;
class taylor{
    private:
    float x,sum=0;
    int n,k;

    public:
    void getdata(){   
        cout<<"Enter x and n: "<<endl;
        cin>>x>>n;
        k=n;
    }
    float sin(){
       for(int i=0;i<=n;i++){
          sum=sum+(float)(pow((-1),i)*(pow(x,(2*i+1))))/(fact(2*i+1));
       }
       cout<<sum<<endl;
       sum=0;
    }
    float cos(){
        for(int i=0;i<=n;i++){
            sum=sum+(float)(pow((-1),i)*(pow(x,(2*i))))/(fact(2*i));
        }
        cout<<sum<<endl;
        sum=0;
    }
    float exp(){
        for(int i=0;i<=n;i++){
            sum=sum+(float)((pow(x,(i))))/(fact(i));
        }
        cout<<sum<<endl;
    }
    int fact(int k){
        if(k<=0)
        return 1;
        else
        return k*fact(k-1);
    }
};
int main(){
    taylor o1;
    o1.getdata();
    o1.sin();
    o1.cos();
    o1.exp();    
}