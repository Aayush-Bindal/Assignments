#include <iostream>
using namespace std;
#include <stack>
/*
4. Write a program to convert an Infix expression into a Postfix expression:
    examples :-

    A+(B*C)   →   ABC*+

    A*(B+C)/D -> ABC+*D/

    A+(B*C-D)/E -> ABC*D-E/+

*/
int precd (char ch){

    if(ch == '*' || ch == '/')return 2;
    if(ch == '+' || ch == '-')return 1;

    return -1;
}
bool isOperator(char ch){
    if(ch == '+' || ch == '-' || ch == '/' || ch == '*')return true;
    return false;
}
string InfixToPostFix(string str){
    string ans="";
    stack <char> s;
    for(char ch : str){

        if(ch == '(') s.push(ch);
        else if (ch == ')' ){
            while(!s.empty() && s.top() != '(' ){
                ans+= s.top();
                s.pop();
            }
            s.pop(); // remove '('
        }
        else if(!isOperator(ch)){
            ans+=ch;
        }
        else{ // isOperator is true;
            while(!s.empty() && precd(s.top()) >= precd(ch) ){
                ans += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }
    while(!s.empty()){
        ans+= s.top();
        s.pop();
    }
    return ans;
}

int main(){
    string ans = InfixToPostFix("(A+B)/C*D");
    cout<<ans<<endl; //AB+C/D*
    cout<<InfixToPostFix("A+(B*C-D)/E"); // ABC*D-E/+
}