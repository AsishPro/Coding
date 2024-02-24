#include <iostream>
#include <iostream>
#include <string.h>
using  namespace std;
int main(){
char name[100]=5000;
char tname[100];
       cout<<"Enter the New Name or <Enter> for no change: ";
        gets(tname);
        strcpy(name,strlen(tname)!=0?tname:name);
        cout<<name;
}