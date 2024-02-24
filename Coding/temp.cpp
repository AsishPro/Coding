#include<iostream>
#define m 50
using namespace std;

class hotel{
    int itemcode[m];
    float itemprice[m];
    int count=0;
    public:
    //  void cnt(void)
    //  {
    //      count =0;
    //  }
void getitem(void){
    cin>>itemcode[count];
    
    cin>>itemprice[count];
    count++;
}
void displaysum(void){
    float sum=0;
    for (int i=0;i<count;i++)
    sum=sum+itemprice[i];
    cout<<sum<<endl;
    
}
void remove(void)
{
    int a;
  
    cin>>a;
    for(int i=0;i<count;i++)
    {
        if(itemcode[i]==a)
        itemprice[i]=0;
    }
    
}
void  displayitems(void)
{
    
    for (int i=0;i<count;i++)
    {
        cout<<itemcode[i]<<"\t";
        cout<< itemprice[i]<<endl;
    }
    
}
};
int main()
{
    hotel order;
    //order.cnt();
    int x;
    while(x!=5)
    {
        cin>>x;
        switch(x)
       { 
        case 1: 
        order.getitem();
        break;
        case 2: 
        order.displaysum();
        break;
        case 3: 
        order.remove();
        break;
        case 4: 
        order.displayitems();
        break;
        default : 
        cout<<"Please enter the valid number."<<endl;
    }
 };
    return 0;
}