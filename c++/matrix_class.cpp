
#include <iostream>
using namespace std;

int main()
{
    int *p=new int[6];
    // for(int i=0;i<2;i++){
    //     p[i]=new int[3];
    // }
    
    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            cin>>*(*p+i)+j;
        }
    }
    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            cout<<*((p+i)+j)<<' ';
        }
        cout<<endl;
    }
    
    printf("Hello World");

    return 0;
}
