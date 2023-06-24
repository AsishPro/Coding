#include <bits/stdc++.h>
using namespace std;
int main()
{
	// Initialize set
	set<string> s={"asish","manoj","reddy"};

	// finding position of 6
	set<string>::iterator pos=s.find("reddy");
	// print element position if it is present in set
    cout<<distance(s.begin(),pos)<<endl;
	if (pos != s.end())
		cout << "Element found at position : "
			<< distance(s.begin(), pos) << endl;
	else
		cout << "Element not present in set";
    return 0;
}

// This code is modified by Susobhan Akhuli
