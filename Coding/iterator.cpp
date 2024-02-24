#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main(){
    vector<int>a(20);
    vector<int>::iterator it;
for ( it =a.begin(); it != a.end(); ++it )
cout << *it << " ";

cout << endl;


}