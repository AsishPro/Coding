#include <iostream>
using namespace std;
template <class x,class y>
void swap(x &a,y &b){
    int temp=b;
    b=a;
    a=b;
}
template <class T>
void bubbleSort(T a[], int n) {
   for(int i=0;i<n-1;i++){
    for(int j=0;j<n-i-1;j++){
      if(a[j]>a[j+1])
          swap(a[j],a[j+1]);
    }
  }
}

int main() {

int a[5] = {10, 50, 30, 40, 20};
int n = sizeof(a) / sizeof(a[0]);
// calls template function
bubbleSort<int>(a, n);
cout << " Sorted array : ";
for (int i = 0; i < n; i++)
cout << a[i] << " ";

cout << endl;

return 0;
}
