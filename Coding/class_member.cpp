#include <iostream>
using namespace std;

template <typename T>
class Array {
private:
	T* ptr;
	int size;

public:
    void insert(int);
    void print(){
	for (int i = 0; i < size; i++)
		cout << " " << *(ptr + i);
	cout << endl;
}

};

template <typename k> 
void Array<k>::insert(int s)
{
	ptr = new k[s];
	size = s;
	for (int i = 0; i < size; i++)
		cin>>ptr[i];
}

int main()
{
	int arr[100];
	Array<int> a;
    a.insert(10);
	a.print();
	return 0;
}
