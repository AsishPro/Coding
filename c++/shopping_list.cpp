#include <iostream>
#include <map>
using namespace std;
class shopping{
     public:
     map<int,float> k;

     void addlist(){
        int code;
        float price;
         cin>>code>>price;
         k[code]=price;
     }
     void displayitem(){    
        for(auto x:k){
            cout<<x.first<<' '<<x.second<<endl;
        }
     } 
      void remove(){
        int code;
        cin>>code;
        k[code]=0;
     }
     void displaytotal(){
        float sum;
        for(auto x:k){
            sum=sum+x.second;
        }
        cout<<sum<<endl;
     }
};
int main(){
    shopping s;
    int ch;
    
    while(1){
        cin>>ch;
     switch(ch){
         case 1:
         s.addlist();
         break;
        case 2:
         s.displaytotal();
         break;
        case 3:
         s.remove();
         break;
        case 4:
         s.displayitem();
         break;
        case 5:
          cout<<"Please Enter a valid number.";
          return 0;
      }
    }  
    return 0; 
}