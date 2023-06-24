// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// Function to return the count of
// increasing subarrays of length k
int cntSubArrays(int* arr, int n, int k)
{
	// To store the final result
	int res = 0;

	int i = 0;
	// Two pointer loop
	while (i < n) {

		// Initialising j
		int j = i + 1;

		// Looping till the subarray increases
		while (j < n and arr[j] >= arr[j - 1])
			j++;

		// Updating the required count
		res += max(j - i + 1, 0);

		// Updating i
		i = j;
	}

	// Returning res
	return res;
}

// Driver code
int main()
{
	int arr[] = {2,3,4,1,6 };
	int n = sizeof(arr) / sizeof(int);
	int k = 2;

	cout << cntSubArrays(arr, n, k);

	return 0;
}
