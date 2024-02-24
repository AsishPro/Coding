#include <iostream>
#include <conio.h>
using namespace std;
int main(){
    char user[100],pass[100];
    cout<<"Enter the Username: ";
    cin>>user;
    cout<<"Enter the Password: ";
    int i=0;
    char x;
    while(1){
        x=getch();
    	if(x!=13){
    		cout<<"*";
			pass[i]=x;
			i++;
        } 
    	else break;
    }
    cout<<pass;
}