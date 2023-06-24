#include <bits/stdc++.h>
using namespace std;
void remove_duplicates(int* arr, int& n) {

	unordered_map<int, int> m;
	int k = 0;

	// iterate each element of arr[]
	for (int i = 0; i < n; ++i) {

		// if m.find(x) == m.end() then it means that
		// x is present in the map
		if (m.find(arr[i]) == m.end()) {
			m[arr[i]] = 1; // inserting arr[i] into the map
			arr[k++] = arr[i];
		}

	}

	n = k;
}
int main()
{   
    
    int n,ap,diff;
    cin>>n;
    cin>>ap;
    cin>>diff;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int arr1[ap];
    remove_duplicates(arr1,ap);
    for(int j=0;j<ap;j++){
        cin>>arr1[j];
    }
    int c=0;
    for(int j=0;j<ap;j++){
      for(int i=0;i<n;i++){
            if(abs(arr[i]-arr1[j])<=diff)
               c++;
		}
    }

	cout<<c<<endl;
}