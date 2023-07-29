#include <bits/stdc++.h> 
using namespace std;
int inside(char ch){
    string k="0123456789";
    for(int i=0;i<k.length();i++)
        if(ch==k[i])
            return 1;
    if(ch=='-')
    return 2;
    return 0;
}
int atoi() {
    string str="This is a temp 1232";
    int temp=0;
    for (int i = 0; i < str.length(); i++) {
      if (inside(str[i])==1)
        temp = temp*10 + stoi(string(1,str[i]));
      if (inside(str[i])==2)
        temp=temp*(-1);
        
    }
    return temp;
}