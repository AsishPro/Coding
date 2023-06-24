// You are using GCC
#include <iostream>
#include <vector>
using namespace std;
class matrix{
    private:
    int m;
    int n;
    
    public:
    matrix(){
         cin>>m>>n;
    }
    void getdata(){
        vector<vector<int>> v(m, vector<int> (n, 0)) ;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cin>>v[i][j];
            }
        }
        //  for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<v[i][j]<<' ';
        //     }
        //     cout<<'\n';
        // }
      
    }
    void printd(int a,int b){
        cout<<v[a][b]<<endl;
    }
};

int main(){
      int a,b;
      matrix o1;
      o1.getdata();
    //   cin>>a>>b;
    //   o1.printd(a,b);

}