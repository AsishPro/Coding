#include <bits/stdc++.h>
using namespace std;

int main(){
      map<string,map<int,int>>m;
     
       string s;
       int key,value;
    for(auto itr = m.begin(); itr != m.end(); itr++) {
        for(auto ptr = itr->second.begin(); ptr != itr->second.end(); ptr++) {
           cin>>s;
           cin>>key>>value;
           if(s=="END")
           return 0;
           m[itr].insert(std::pair<int, int>(key, value));
        }
     }
      for(auto itr = m.begin(); itr != m.end(); itr++) {
        for(auto ptr = itr->second.begin(); ptr != itr->second.end(); ptr++) {
              cout << "First key is " << itr->first
                 << " And second key is " << ptr->first
                 << " And value is " << ptr->second << endl;
                 }
     }
         
}