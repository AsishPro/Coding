
#include <iostream>
#include <vector>
using namespace std;
class matrix{
    public:
    int m,n;
    int v[100][100];
    public:
    void getdata(){
        cin>>m>>n;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cin>>v[i][j];
            }
        }
    }
     void add(matrix o1,matrix o2){
          m=o1.m;
          n=o1.n;
          for(int i=0;i<o1.m;i++){
            for(int j=0;j<o1.n;j++){
               v[i][j]=o1.v[i][j]+o2.v[i][j];
            }
          }
    }
    void product(matrix o1,matrix o2){
          m=o1.m;
          n=o1.n;
          for(int i=0;i<o1.m;i++){
            for(int j=0;j<o1.n;j++){
               v[i][j]=o1.v[i][j]*o2.v[i][j];
            }
          }
    }
    void subs(matrix o1,matrix o2){
          m=o1.m;
          n=o1.n;
          for(int i=0;i<o1.m;i++){
            for(int j=0;j<o1.n;j++){
               v[i][j]=o1.v[i][j]-o2.v[i][j];
            }
          }
    }
    void trans(matrix o1){
          for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
               v[i][j]=o1.v[j][i];
            }
          }
    }
    void printd(){
        cout<<endl;       
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
              cout<<v[i][j]<<' ';
            } 
            cout<<'\n';
        }
               
    }
};

int main(){
      matrix o1,o2;
      o1.getdata();  //get matrix size + data twice 
      o2.getdata();  
      matrix o3;

      //addition of two matrix
      o3.add(o1,o2);
      cout<<"addition is";
      o3.printd();

      //product of two matrix
      o3.product(o1,o2);
      cout<<"product is";
      o3.printd();

      //substraction of two matrix
      o3.subs(o1,o2);
      cout<<"Substraction is";
      o3.printd();

      o3.trans(o1);
      cout<<"Transpose is ";
      o3.printd();
}