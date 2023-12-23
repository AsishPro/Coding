#include <bits/stdc++.h>
using namespace std;
void keycheck(string str){
    if(str == "for" || str == "while" || str == "do" || str == "int" ||
        str == "float" || str == "char" || str == "double" ||
        str == "static" || str == "switch" || str == "case")
        cout <<str<<" : keyword"<<endl;
    else
        cout<<str<<" : identifier"<<endl;
}
int main(){
    ifstream file("input.c");
    char c;
    file.get(c);

    ofstream f1("identifier.txt");
    ofstream f2("special.txt");
    ofstream f3("numbers.txt");
    int l=0;
    while(c!=EOF){
        if(isalpha(c)){
            f1.put(c);
            c=file.get();
            while(isalpha(c)||isdigit(c)||c=='_'||c=='.'){
                f1.put(c);
                c=file.get();
            }
            f1.put(' ');
            file.unget();
        }
        else if (c=='"'){
            c=file.get();
            while(c!='"'){
                c=file.get();
            }
        }
        else if (isdigit(c)){
            f3.put(c);
            c=file.get();
            while(isdigit(c)){
                f3.put(c);
            }
            file.unget();
        }
        else if(c==' '|| c=='\t'){
            c=file.get();
            continue;
        }
        else if(c=='\n'){
            l++;
        }
        else{
            f2.put(c);
        }
        c=file.get();
    }
    f1.close();
    f2.close();
    f3.close();
    file.close();

    file.open("identifier.txt");
    
    c=file.get();
    string t="";
    while(c!=EOF){
        if(c==' '){
            keycheck(t);
            t="";
        }
        else{
            t+=c;
        }
        c=file.get();
    }
    file.close();
    cout<<"Number of Lines: "<<l<<endl;
}