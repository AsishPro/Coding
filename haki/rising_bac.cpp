#include <bits/stdc++.h>
using namespace std;

int countSetBits(int n)
{
    if (n == 0)
        return 0;
    else
        return (n & 1) + countSetBits(n >> 1);
}
 
// driver code
int main()
{
   int n;
   cin>>n;
   
    // function calling
    cout << countSetBits(n);
    return 0;
}