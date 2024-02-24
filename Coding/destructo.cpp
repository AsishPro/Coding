#include <iostream>
using namespace std;
class Book{
public:
string Name;
static int counter;
Book(){
counter++;
cout<<counter<<endl;
Name="Default";
}
Book(string name){
Book();
Name=name;
}
Book(const Book& b){
Book();
Name=b.Name;
}
~Book(){
counter--;
cout<<counter<<endl;
}
};
int Book::counter=0;
int main(){
    Book b1,b2,b3,b4;
}