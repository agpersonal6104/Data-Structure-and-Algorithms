#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <algorithm> // For remove_if

using namespace std;

// Function to check if a character is an operator
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

// Function to get precedence of an operator
int getPrecedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Function to process the operation and construct the expression
string processOperation(const string& a, const string& b, char op) {
    return "(" + a + " " + op + " " + b + ")";
}

// Function to parse and construct the expression using operator precedence parsing
string parseExpression(const string& expression) {
    stack<string> values; // Stack to store operands as strings
    stack<char> operators; // Stack to store operators

    for (size_t i = 0; i < expression.length(); i++) {
        char c = expression[i];

        // If the character is an alphabetic variable, push it to the values stack
        if (isalpha(c)) {
            values.push(string(1, c));
        }
        // If the character is an operator
        else if (isOperator(c)) {
            while (!operators.empty() && getPrecedence(operators.top()) >= getPrecedence(c)) {
                if (values.size() < 2) {
                    throw runtime_error("Invalid expression");
                }
                string b = values.top(); values.pop();
                string a = values.top(); values.pop();
                char op = operators.top(); operators.pop();
                values.push(processOperation(a, b, op));
            }
            operators.push(c);
        }
        // Handle invalid characters
        else {
            throw runtime_error("Invalid character in expression");
        }
    }

    // Perform remaining operations
    while (!operators.empty()) {
        if (values.size() < 2) {
            throw runtime_error("Invalid expression");
        }
        string b = values.top(); values.pop();
        string a = values.top(); values.pop();
        char op = operators.top(); operators.pop();
        values.push(processOperation(a, b, op));
    }

    if (values.size() != 1) {
        throw runtime_error("Invalid expression");
    }

    return values.top();
}

int main() {
    string expression;
    cout << "Enter an expression: ";
    getline(cin, expression); // Use getline to allow spaces in the input

    // Remove spaces from the input expression
    expression.erase(remove_if(expression.begin(), expression.end(), ::isspace), expression.end());

    try {
        string result = parseExpression(expression);
        cout << "Parsed Expression: " << result << endl;
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}