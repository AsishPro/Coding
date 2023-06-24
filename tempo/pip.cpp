#include <bits/stdc++.h>
using namespace std;

void permute(string str, int l, int r) {
if (l == r) {
cout << str << " ";
return;
}
else{
for (int i = l+1; i <= r; i++) {
swap(str[l], str[i]);
permute(str, l+1, r);
swap(str[l], str[i]);
}
}
}

void permutations(string str) {
int n = str.length();
permute(str, 0, n-1);
}

int main()
{
permutations("ABCDEFGHIJKL");
return 0;
}
