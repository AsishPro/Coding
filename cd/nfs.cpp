#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

struct NFATransition {
    int startState;
    char symbol;
    int endState;
};

class NFA {
public:
    std::vector<int> states;
    std::vector<NFATransition> transitions;
    int initialState;
    int acceptState;

    NFA(int initialState, int acceptState) : initialState(initialState), acceptState(acceptState) {
        states.push_back(initialState);
        states.push_back(acceptState);
    }

    void addTransition(int startState, char symbol, int endState) {
        transitions.push_back({startState, symbol, endState});
        states.push_back(startState);
        states.push_back(endState);
    }
};

NFA regexToNFA(const std::string& regex) {
    std::stack<NFA> nfaStack;
    int stateCounter = 0;

    for (char symbol : regex) {
        if (symbol == '*') {
            // Closure operation
            NFA nfa = nfaStack.top();
            nfaStack.pop();

            int newInitialState = stateCounter++;
            int newAcceptState = stateCounter++;

            nfa.addTransition(newAcceptState, 'ε', nfa.initialState);
            nfa.addTransition(newAcceptState, 'ε', newAcceptState);
            nfa.addTransition(newInitialState, 'ε', nfa.initialState);
            nfa.addTransition(newInitialState, 'ε', newAcceptState);

            nfa.initialState = newInitialState;
            nfa.acceptState = newAcceptState;

            nfaStack.push(nfa);
        } else {
            // Basic operation (symbol)
            int initialState = stateCounter++;
            int acceptState = stateCounter++;
            nfaStack.push(NFA(initialState, acceptState));
            nfaStack.top().addTransition(initialState, symbol, acceptState);
        }
    }

    if (nfaStack.size() != 1) {
        std::cerr << "Invalid regular expression!" << std::endl;
        exit(1);
    }

    return nfaStack.top();
}

void drawNFA(const NFA& nfa) {
    std::ofstream dotFile("nfa.dot");
    dotFile << "digraph NFA {" << std::endl;
    
    for (int state : nfa.states) {
        dotFile << "  " << state;
        if (state == nfa.initialState) {
            dotFile << " [label=\"Start\", shape=circle]";
        } else if (state == nfa.acceptState) {
            dotFile << " [label=\"Accept\", shape=doublecircle]";
        } else {
            dotFile << " [shape=circle]";
        }
        dotFile << std::endl;
    }
    
    for (const NFATransition& transition : nfa.transitions) {
        dotFile << "  " << transition.startState << " -> " << transition.endState << " [label=\"" << transition.symbol << "\"]" << std::endl;
    }

    dotFile << "}" << std::endl;
    dotFile.close();
}

int main() {
    std::string regex;
    std::cout << "Enter regular expression: ";
    std::cin >> regex;

    NFA nfa = regexToNFA(regex);
    drawNFA(nfa);
    
    std::cout << "NFA drawn and saved to 'nfa.dot'. Use Graphviz tools to visualize the NFA." << std::endl;

    return 0;
}
