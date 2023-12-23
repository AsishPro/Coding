#include <bits/stdc++.h>
using namespace std;
int main(){
    
    // string path;
    // cin>>path;
    string path="input.c";
    ifstream file(path);
    
    int c=0,w=0,l=0;
    if(!file){
        printf("File not found");
        return 0;
    }
    char ch=file.get();
    string temp="";
    while (ch!=EOF){
        c+=1;
        if (ch==' ' || ch=='\t' ||ch == '\0')
            w++;
        if (ch=='\n')
            l++;
        ch=file.get();
    }

    if (ch!='\n' || ch!='\0')
        l+=1;

    cout<<l<<" "<<w<<" "<<c;
    return 0;
    
}