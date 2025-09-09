#include <iostream>
#include <stack>
using namespace std;

/*
3. Write a program that checks if an expression has balanced parentheses.
*/
bool isValid(string str) {
    stack<char> s;
    for (char ch : str) {
        if (ch == '(' || ch == '{' || ch == '[') s.push(ch);
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.empty()) return false;
            char top = s.top();
            if ((top == '{' && ch == '}') ||
                (top == '[' && ch == ']') ||
                (top == '(' && ch == ')'))
                s.pop();
            else return false;
        }
    }
    return s.empty();
}

int main() {
    string expr;
    cout << "Enter an expression: ";
    cin >> expr;

    if (isValid(expr))
        cout << "Balanced" << endl;
    else
        cout << "Not Balanced" << endl;

    return 0;
}
