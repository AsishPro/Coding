#include <iostream>
#include <ctime>
using namespace std;
class deco{
    public:
    void a(){
    cout<<"";
   }  
    void b(){
    cout<<"";
  }
   void c(){
    cout<<"\n******************";
   }
   void d(){
    cout<<"\t\t\t\t\t";
   }
};
int main(){

    cout<<"-------------> SRM AP salary slip <--------------"<<endl;
    time_t now = time(0);
    tm *t = localtime(&now);
    cout<<"Day: "<< t->tm_mday << endl; 
    cout<<"Month: "<< 1 + t->tm_mon<<endl;
    cout<<"Year: " << 1900 + t->tm_year<<endl<<endl;

    cout<<"\tEarnings\t|\tDeductions"<<endl;
    cout<<"\t"<<"Basic Sal : "<<o[i].sal<<"|"<<"Provident Fund : "<<o[i].pf<<endl;
    cout<<"\t"<<"DA : "<<o[i].da<<"|"<<"Professional Tax : "<<o[i].pt<<endl;
    cout<<"\t"<<"HRA : "<<o[i].hra<<"|"<<"Tax Deducted At Source : "<<o[i].tds<<endl;
    cout<<"\t"<<"Medical Allowance : "<<o[i].ma<<"|"<<"Leave Deduction : "<<o[i].leave<<endl;
    cout<<"\t"<<"Travel Allowance : "<<o[i].ta<<"|"<<endl;
    cout<<"\t"<<"Special Allowance : "<<o[i].special<<"|"<<endl;
    float ded=o[i].pt+o[i].pf+o[i].leave;
    cout<<"\t"<<"CTC(month) : "<<o[i].ctc<<"|"<<"Net Deduction : "<<ded<<endl;
    cout<<endl;
    cout<<"\t"<<"Net Salary : "<<o[i].net<<endl
    

}   


