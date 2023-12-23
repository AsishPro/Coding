#include <bits/stdc++.h>
using namespace std;

void keyword(const string& str) {
    if (str == "for" || str == "while" || str == "do" || str == "int" ||
        str == "float" || str == "char" || str == "double" ||
        str == "static" || str == "switch" || str == "case")
        cout << "\n" << str << " is a keyword";
    else
        cout << "\n" << str << " is an identifier";
}

int main() {
    ifstream file("input.c");
    ofstream f1("identifier.txt");
    ofstream f2("specialchar.txt");

    char c;
    int num[100];
    int l = 0;
    int tokenvalue = 0;
    int i = 0;
    string str;

    c=file.get();
    int z=0;
    while (c!= EOF && z<10) {
        cout<<c;
        z++;
        if (isdigit(c)) {
            tokenvalue = c - '0';
            file.get(c);
            while (isdigit(c)) {
                tokenvalue = tokenvalue * 10 + (c - '0');
                file.get(c);
            }
            num[i++] = tokenvalue;
            file.unget();
        } else if (isalpha(c)) {
            f1.put(c);
            file.get(c);
            while (isdigit(c) || isalpha(c) || c == '_' || c == '$') {
                f1.put(c);
                file.get(c);
            }
            f1.put(' ');
            file.unget();
        } else if (c == ' ' || c == '\t') {
            cout << " ";
        } else if (c == '\n') {
            l++;
        } else {
            f2.put(c);
        }
        file.get(c);
    }

    f1.close();
    f2.close();
    file.close();

    cout << "\nThe numbers in the program are:";
    for (int j = 0; j < i; j++)
        cout << " " << num[j] << " ";
    cout << "\n";

    file.open("identifier.txt");
    int k = 0;
    cout << "The keywords and identifiers are:";
    file.get(c);
    while (c!= EOF) {
        if (c != ' ')
            str += c;
        else {
            keyword(str);
            str="";
        }
        file.get(c);
    }

    file.close();

    file.open("specialchar.txt");
    cout << "\nSpecial characters are";
    file.get(c);
    while (c!= EOF){
        cout << " " << c << " ";
        file.get(c);
    }
    cout << "\n";

    file.close();

    cout << "Total no. of lines are: " << l;

    return 0;
}

