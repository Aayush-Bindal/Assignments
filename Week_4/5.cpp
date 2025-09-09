#include <iostream>
using namespace std;
#include <stack>

/*
problem statement:

5. Write a program for the evaluation of a Postfix expression
*/
/*
summery:
we treverse normally and put operand in stack and if we found operator while
treversing remove 2 element from stack and perform operation on them and again put them in stack
at end we have top of stack as answer

*/
int postfixEval(string str){
    stack<int>s;
    for(int i = 0 ; i < str.size() ; i++){
        char ch = str[i];
        if(ch != '+' && ch != '-' && ch != '*' && ch != '/'  ){ // operand condition
            s.push(ch-'0');
        }
        else{
            if(ch == '+'){
                int val2 = s.top();
                s.pop();
                int val1 = s.top();
                s.pop();
                s.push(val1 + val2);
            }
            else if( ch == '*'){
                int val2 = s.top();
                s.pop();
                int val1 = s.top();
                s.pop();
                s.push(val1 *val2);
            }
            else if( ch == '/'){
                int val2 = s.top();
                s.pop();
                int val1 = s.top();
                s.pop();
                s.push(val1 / val2);
            }
            else{
                int val2 = s.top();
                s.pop();
                int val1 = s.top();
                s.pop();
                s.push(val1-val2);
            }
        }
    }
    return s.top();
}
int main(){
    cout<< postfixEval("23*54*+9-")<<endl;//17
    cout<<postfixEval("93-42*+")<<endl;// 14
    return 0;
}
