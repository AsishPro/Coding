#include <iostream>
using namespace std;
int dp[100]={-1};

// this function returns the number of
// arrangements to form 'n'
int solve(int n)
{
// base case
if (n < 0)
	return 0;
if (n == 0)
	return 1;

// checking if already calculated
if (dp[n]!=-1)
	return dp[n];

// storing the result and returning
return dp[n] = solve(n-1) + solve(n-3) + solve(n-5);
}
int main(){
    cout<<solve(7);
    cout<<dp[7];
}
