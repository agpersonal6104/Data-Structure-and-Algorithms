#include <iostream>
#include <string>
using namespace std;

void eliminateLeftRecursion(char nonTerminal, string alpha, string beta) {
    string newNonTerminal = string(1, nonTerminal) + "'"; // Create a new non-terminal (e.g., A')
    cout << nonTerminal << " -> " << beta << newNonTerminal << endl;
    cout << newNonTerminal << " -> " << alpha << newNonTerminal << " | ε" << endl;
}

int main() {
    string production, alpha, beta;
    char nonTerminal;
    bool hasLeftRecursion = false;

    cout << "Enter the production (E.g., A->Aa|b): ";
    cin >> production;

    nonTerminal = production[0]; // Extract the non-terminal
    size_t arrowPos = production.find("->");
    if (arrowPos == string::npos) {
        cout << "Invalid production format!" << endl;
        return 1;
    }

    size_t pipePos = production.find("|");
    if (pipePos == string::npos) {
        cout << "The given production does not have left recursion." << endl;
        return 0;
    }

    alpha = production.substr(arrowPos + 2, pipePos - (arrowPos + 2)); // Extract alpha
    beta = production.substr(pipePos + 1); // Extract beta

    if (alpha[0] == nonTerminal) {
        hasLeftRecursion = true;
        eliminateLeftRecursion(nonTerminal, alpha.substr(1), beta);
    }

    if (!hasLeftRecursion) {
        cout << "The given production does not have left recursion." << endl;
    }

    return 0;
}