#include <iostream>
#include <sstream>
#include <vector>

struct ThreeAddressCode {
    std::string op;
    std::string arg1;
    std::string arg2;
    std::string result;
};

class ThreeAddressCodeGenerator {
public:
    std::vector<ThreeAddressCode> generate(const std::string& expression) {
        std::istringstream iss(expression);
        std::string token;
        std::vector<ThreeAddressCode> code;
        std::string result = getNextTempVar();

        while (iss >> token) {
            if (isOperator(token)) {
                std::string op = token;
                std::string arg1 = code.back().result;
                std::string arg2;
                iss >> arg2;
                result = getNextTempVar();

                code.push_back({op, arg1, arg2, result});
            } else {
                result = token;
            }
        }

        return code;
    }

private:
    int tempVarCount = 0;

    std::string getNextTempVar() {
        return "t" + std::to_string(tempVarCount++);
    }

    bool isOperator(const std::string& token) {
        return token == "+" || token == "-" || token == "*" || token == "/";
    }
};

int main() {
    std::string expression;
    std::cout << "Enter arithmetic expression: ";
    std::getline(std::cin, expression);

    ThreeAddressCodeGenerator generator;
    std::vector<ThreeAddressCode> code = generator.generate(expression);

    std::cout << "Generated Three-Address Code:" << std::endl;
    for (const auto& tac : code) {
        std::cout << tac.result << " = " << tac.arg1 << " " << tac.op << " " << tac.arg2 << std::endl;
    }

    return 0;
}
