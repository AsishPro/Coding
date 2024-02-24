#include <iostream>
#include <string.h>
using namespace std;

int main(){
    char temp[100];
    char depart[100]="asisis";
     gets(temp);
     strcpy(depart,strlen(temp)!=0?temp:depart);
     cout<<depart;
}