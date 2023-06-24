#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace std::chrono;
void cube(){
  vector<int> values(10000);
    auto f = []() -> int { return rand() % 10000; };
 
    // Fill up the vector
    generate(values.begin(), values.end(), f);
    sort(values.begin(), values.end());
 
}

int main(){
    auto start = high_resolution_clock::now();
    cube();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << duration.count()<< endl;
}