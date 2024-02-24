// C++ program to take unknown number
// of integers from user.
#include <iostream>
using namespace std;
int main()
{
	int input;
	int count = 0;
	cout << "To stop enter anything except integer";
	cout << "\nEnter Your Input::";

	// cin returns false when anything
	// is entered except integer
	while (cin >> input)
		count++;
	cout << "\nTotal number of inputs entered: "
		<< count;
	return 0;
}

//This code is updated by Susobhan Akhuli
