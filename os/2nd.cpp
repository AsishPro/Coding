
#include <bits/stdc++.h>
using namespace std;


int min(int x, int y, int z){ 
    return min(min(x, y), z); 
}

int distance(string str1, string str2, int m, int n){

	if (m == 0)
		return n;
	if (n == 0)
		return m;
	if (str1[m - 1] == str2[n - 1])
		return distance(str1, str2, m - 1, n - 1);
	return 1+distance(str1,str2, m - 1,n - 1);
}
int main(){
	
	string a;
    cin>>a;
	string b;
    cin>>b;
	cout << distance(a,b,a.length(),b.length());
	return 0;
}
