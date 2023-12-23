#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iomanip>

using namespace std;

class PrettyTable {
public:
    PrettyTable(const vector<string>& fields) : fields(fields) {}

    void add_row(const vector<string>& row) {
        rows.push_back(row);
    }

    void print_table() {
        cout << setw(10);
        for (const auto& field : fields) {
            cout << setw(15) << field;
        }
        cout << endl;

        for (const auto& row : rows) {
            for (const auto& cell : row) {
                cout << setw(15) << cell;
            }
            cout << endl;
        }
    }

private:
    vector<string> fields;
    vector<vector<string>> rows;
};

vector<string> while_loop(const vector<string>& cleaned_code) {
    vector<string> final_code;
    int while_idx = -1;

    for (size_t i = 0; i < cleaned_code.size(); ++i) {
        string codeline = cleaned_code[i];

        if (codeline.find("while") != string::npos) {
            while_idx = static_cast<int>(i);
            // The loop condition would be enclosed in brackets
            size_t start_idx = codeline.find('(');
            size_t end_idx = codeline.find(')');
            // Select the substring between start_idx and end_idx
            string bool_condn = codeline.substr(start_idx, end_idx - start_idx + 1);
            // Replace with
            final_code.push_back("if (!" + bool_condn + ") goto " + to_string(while_idx + 2));
        } else if (codeline.find("}") != string::npos) {
            final_code.push_back("goto " + to_string(while_idx + 1));
            // Replace with the correct index
            final_code[while_idx] = final_code[while_idx].replace(final_code[while_idx].find("goto"), 4, to_string(i + 2));
            while_idx = -1;
        } else {
            final_code.push_back(codeline);
        }
    }

    return final_code;
}

int main() {
    ifstream file("code.txt");
    vector<string> code;
    string line;

    cout << "The Statement is:" << endl;
    while (getline(file, line)) {
        cout << line << endl;
        code.push_back(line);
    }

    vector<string> cleaned_code;
    for (const auto& line : code) {
        if (!line.empty()) {
            if (line.back() == '\n') {
                // don't include the \n at the end of each line
                cleaned_code.push_back(line.substr(0, line.size() - 1));
            } else {
                // strip() removes the trailing whitespaces on both ends of string
                cleaned_code.push_back(line);
            }
        }
    }

    vector<string> intermediate_code;
    vector<string> updations;
    for (size_t i = 0; i < cleaned_code.size(); ++i) {
        const string& codeline = cleaned_code[i];
        if (codeline.find("for") != string::npos) {
            // for(init; condition; update1, update2, update3, etc.)\n
            size_t start = codeline.find('(');
            size_t end = codeline.rfind(')');
            string conditions = codeline.substr(start + 1, end - start - 1);
            istringstream iss(conditions);
            string initialization, break_condn, updation;
            iss >> initialization >> break_condn;
            intermediate_code.push_back(initialization);
            intermediate_code.push_back("while (" + break_condn + ") {");
        } else if (codeline.find("}") != string::npos) {
            for (const auto& updation : updations) {
                intermediate_code.push_back(updation + ";");
            }
            intermediate_code.push_back("}");
        } else {
            intermediate_code.push_back(codeline);
        }
    }

    vector<string> final_code = while_loop(intermediate_code);

    cout << "\nThe Three Code generated is:\n";
    PrettyTable table({"Index", "Code"});
    for (size_t i = 0; i < final_code.size(); ++i) {
        table.add_row({to_string(i + 1), final_code[i]});
    }

    table.print_table();

    return 0;
}
