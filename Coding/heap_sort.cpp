#include <iostream>
#include <vector>
using namespace std;
class heap{

    private:
    int size=0;
    int p[100];

    public:
    void insert(int n){
        size=size+1;
        int i=size;
        p[i]=n; 
        while(i>1){
          int parent=i/2;
          if(p[parent]<p[i]){
             swap(p[parent],p[i]);
             i=parent;
          }
          else
          return ;
       } 
    }
    void deleter(){
    if(size!=0){
       p[1]=p[size];
       size--;
       int i=1;
       while(i<size){
        int l=2*i;
        int r=2*i+1;
        if(l<size and p[l]>p[i]){
         swap(p[l],p[i]);
         i=l;
        }
        else if(r<size and p[r]>p[i]){
         swap(p[r],p[i]);
         i=r;
        }
        else
        return ;
       }
    }
    else
    cout<<"No elements to delete"<<endl;        
       } 

    void print(){
        for(int i=1;i<=size;i++){
            cout<<p[i]<<' ';
        }
    }
};
void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=a;
}
int main(){
   heap h;
   h.insert(4);
   h.insert(9);
   h.insert(6);
   h.print();
}