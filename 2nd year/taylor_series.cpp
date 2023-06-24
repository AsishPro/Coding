#include <iostream>
#include <math.h>
using namespace std;
class taylor{
    private:
    float x,sum=0;
    int n,k;

    public:
    void getdata(){   
        cin>>x>>n;
        k=n;
    }
    float sine(){
       while(n--){
       sum=sum+(pow((-1),n)*(pow(x,(2*n+1))))/(fact(2*n+1));
       }
       sum=sum+(pow(x,(1)))/(fact(1));
       //last case edit cheyra (nen rasinde)
       cout<<sum<<endl;
       sum=0; 
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
}