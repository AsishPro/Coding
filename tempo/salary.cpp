#include <iostream>
#include <conio.h>
using namespace std;
// void gotoxy(int X, int Y)
// {
//     COORD coordinates;
//     coordinates.X = X;
//     coordinates.Y = Y;
//     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
// }
void gotoxy(int x, int y) { 
    printf("%c[%d;%df", 0x1B, y, x); 
} 

int main(){
    char s[10];
    int i=0;
    gotoxy(20,10);
    cout<<"Enter the password: ";
    while(i<10){
        char x=getch();
        if(x!=13){
        s[i]=x;
        cout<<'*';
        i++;
    }
        else{ 
        cout<<"End of program"<<endl;
        break;
        }
    }
}