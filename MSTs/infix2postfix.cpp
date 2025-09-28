#include <iostream>
#include <stack>
#include <string>
using namespace std;

int precedence(char op) {
    switch(op) {
        case '^':
            // Highest possible precedence (typically for exponentiation)
            return 4;
        case '%':
        case '*':
        case '/':
            // High precedence
            return 3;
        case '+':
        case '-':
            // Medium precedence
            return 2;
        case '&':
            // Lowest precedence listed in the table
            return 1;
        case '(':
            // Lowest precedence on the stack, ensuring it isn't popped
            // by any operator until ')' is found.
            return 0;
        default:
            // For any other character (operands, etc.)
            return -1;
    }
}


bool isOperand (char c) {
    if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z') {
        return 1;
    }
    return 0;
}

string convertToPost(string s) {
    int i = 0;
    stack <char> st;
    string ans = "";

    while (i < s.length()) {
        if (isOperand(s[i])) {
            ans = ans + s[i];
        }
        else if (s[i] == '(') {
            st.push(s[i]);
        }
        else if (s[i] == ')') {
            while (st.top() != '(') {
                ans = ans + st.top();
                st.pop();
            }
            st.pop();
        }
        else {
            while (!st.empty() && precedence(st.top()) >= precedence(s[i])) {
                ans = ans + st.top();
                st.pop();                
            }
            st.push(s[i]);
        }
        i++;
    }

    while (!st.empty()) {
        ans = ans + st.top();
        st.pop();
    }

    return ans;
}


// A∗(B&D/E)−F∗(G%H/K)
int main() {
    string in;
    string pos;

    cout << "Enter a infix string: " << endl;
    getline (cin, in);

    pos = convertToPost(in);
    cout << "Infix: " << in << endl;
    cout << "Postfix: " << pos << endl;
}