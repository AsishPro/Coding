#include <iostream>
using namespace std;
class Book{
public:
string Name;
Book(){
Name="Default";
}
private:
Book(const Book& b)
{
Name=b.Name;
}
};
int main(){
    Book b1;
Book b2 = b1;// Copy Constr.
Book t1, t2;
t1=t2;
}