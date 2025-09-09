#include <iostream>
using namespace std;
#include <vector>
#include <stack>
/*
2. Given a string, reverse it using STACK. For example “DataStructure” should be output as
“erutcurtSataD.”
*/
int main(){
    string str = "DataStructure" ;
    stack<char>s;
    for(int i = 0 ; i < str.size() ; i++)s.push(str[i]);
    str = "";
    while(!s.empty()){
        str+= s.top();
        s.pop();
    }
    cout<<str;
    return 0;
}