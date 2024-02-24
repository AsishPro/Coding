#include <iostream>
using namespace std;
int main(){
    int a[2][3]={10,11,12,
                 13,14,15};
    int *p=*a;
    cout<<*(*(a+1)+2)<<endl;
    cout<<*(p+5)<<endl;
    
    //*a= address of first row while *p= value of first element
    cout<<*p<<endl;
    //*(a+i) = a[i]  in single dimension array refers to each row address
    // *(a+i)   -> address of each row
    //**a == a[0][0] == *(a[0]+0) == *(*(a+0)+0)

    cout<<*a<<endl;
    cout<<**(a+1)<<endl;
    //a[0][3]

    cout<<*(*(a)+3)<<endl;
    cout<<*(*(a)+4)<<endl;

    //a[1][0] == a[0][3]
    //a[1][1] == a[0][4]
    cout<<*(*(a+1)+0)<<endl;
}