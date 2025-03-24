#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

// Function to find the longest common prefix
string findLongestCommonPrefix(const vector<string>& productions) {
    if (productions.empty()) return "";
    string prefix = productions[0];
    for (size_t i = 1; i < productions.size(); ++i) {
        size_t j = 0;
        while (j < prefix.size() && j < productions[i].size() && prefix[j] == productions[i][j]) {
            ++j;
        }
        prefix = prefix.substr(0, j);
        if (prefix.empty()) break;
    }
    return prefix;
}

// Function to left factor a grammar
void leftFactorGrammar(const map<string, vector<string>>& grammar) {
    for (const auto& rule : grammar) {
        string nonTerminal = rule.first;
        vector<string> productions = rule.second;

        string prefix = findLongestCommonPrefix(productions);
        if (!prefix.empty() && prefix.size() > 0) {
            cout << nonTerminal << " -> " << prefix << nonTerminal << "'\n";
            cout << nonTerminal << "' -> ";
            for (size_t i = 0; i < productions.size(); ++i) {
                if (productions[i].substr(0, prefix.size()) == prefix) {
                    string suffix = productions[i].substr(prefix.size());
                    if (suffix.empty()) suffix = "ε"; // epsilon for empty production
                    cout << suffix;
                    if (i != productions.size() - 1) cout << " | ";
                }
            }
            cout << endl;
        } else {
            cout << nonTerminal << " -> ";
            for (size_t i = 0; i < productions.size(); ++i) {
                cout << productions[i];
                if (i != productions.size() - 1) cout << " | ";
            }
            cout << endl;
        }
    }
}

int main() {
    map<string, vector<string>> grammar;
    int n;
    cout << "Enter the number of non-terminals: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        string nonTerminal;
        cout << "Enter non-terminal: ";
        cin >> nonTerminal;

        int m;
        cout << "Enter the number of productions for " << nonTerminal << ": ";
        cin >> m;

        vector<string> productions(m);
        cout << "Enter the productions (separated by space): ";
        for (int j = 0; j < m; ++j) {
            cin >> productions[j];
        }

        grammar[nonTerminal] = productions;
    }

    cout << "\nLeft Factored Grammar:\n";
    leftFactorGrammar(grammar);

    return 0;
}