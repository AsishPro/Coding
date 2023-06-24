#include <iostream>
using namespace std;
int main(){
    int a[3][3]={1,2,3,4,5,6,7,8,9};
    int sum[3][3]={0};

   //  for(int x = 0; x <3; x++)
   //     for (int y = 0; y <3; y++)
   //         sum[x][y]=0;

    for(int x = 0; x <3; x++) {
       for (int y = 0; y <3; y++){
         cout<<a[x][y]<<" ";
      }
      cout<<endl;
    }

     cout<<endl;

    for(int x = 0; x <3; x++){
       for (int y = 0; y <3; y++){

        if((x-1>0)||(y-1)>0)
         sum[x][y] = max(sum[x][y-1],sum[x-1][y])+a[x][y];
        else{
        if(x-1>0 && y-1<0)
           sum[x][y]=a[x-1][y];
        else {
           sum[x][y]=a[x][y-1];         
        }
        sum[x][y]+=a[x][y];
      }
    }
   }
    for(int x = 0; x <3; x++) {
       for (int y = 0; y <3; y++){
         cout<<sum[x][y]<<" ";
      }
      cout<<endl;
    }


}