#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

map<char, set<char>> first, follow;
map<char, vector<string>> productions;
set<char> nonTerminals, terminals;

void calculateFirst(char symbol) {
    if (!isupper(symbol)) { // If the symbol is a terminal
        first[symbol].insert(symbol);
        return;
    }

    for (const string &prod : productions[symbol]) {
        for (size_t i = 0; i < prod.size(); ++i) {
            char current = prod[i];
            if (current == symbol) continue; // Avoid left recursion

            calculateFirst(current);
            first[symbol].insert(first[current].begin(), first[current].end());
            first[symbol].erase('ε'); // Remove ε temporarily

            if (first[current].find('ε') == first[current].end()) break; // Stop if ε is not in First(current)
            if (i == prod.size() - 1) first[symbol].insert('ε'); // Add ε if it's the last symbol
        }
    }
}

void calculateFollow(char symbol) {
    if (symbol == productions.begin()->first) follow[symbol].insert('$'); // Add $ to the start symbol

    for (const auto &prod : productions) {
        char nonTerminal = prod.first;
        for (const string &rule : prod.second) {
            for (size_t i = 0; i < rule.size(); ++i) {
                if (rule[i] == symbol) {
                    if (i + 1 < rule.size()) { // If there is a symbol after the current one
                        char next = rule[i + 1];
                        follow[symbol].insert(first[next].begin(), first[next].end());
                        follow[symbol].erase('ε'); // Remove ε from Follow
                    }
                    if (i + 1 == rule.size() || first[rule[i + 1]].count('ε')) { // If it's the last symbol or ε is in First(next)
                        calculateFollow(nonTerminal);
                        follow[symbol].insert(follow[nonTerminal].begin(), follow[nonTerminal].end());
                    }
                }
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of productions: ";
    cin >> n;

    cout << "Enter the productions (e.g., E=TR):\n";
    for (int i = 0; i < n; ++i) {
        string input;
        cin >> input;
        char nonTerminal = input[0];
        string production = input.substr(2);

        productions[nonTerminal].push_back(production);
        nonTerminals.insert(nonTerminal);

        for (char c : production) {
            if (!isupper(c) && c != 'ε') terminals.insert(c); // Add terminals
        }
    }

    for (char nonTerminal : nonTerminals) calculateFirst(nonTerminal);
    for (char nonTerminal : nonTerminals) calculateFollow(nonTerminal);

    cout << "\nFirst Sets:\n";
    for (const auto &entry : first) {
        cout << entry.first << ": { ";
        for (char c : entry.second) cout << c << " ";
        cout << "}\n";
    }

    cout << "\nFollow Sets:\n";
    for (const auto &entry : follow) {
        cout << entry.first << ": { ";
        for (char c : entry.second) cout << c << " ";
        cout << "}\n";
    }

    return 0;
}