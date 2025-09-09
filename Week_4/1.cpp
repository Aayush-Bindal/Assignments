#include <iostream>
using namespace std;
#include <vector>
/*
1. Develop a menu driven program demonstrating the following operations on a Stack using array:
(i) push(), (ii) pop(), (iii) isEmpty(), (iv) isFull(), (v) display(), and (vi) peek().
*/
class stack{
private:
    vector<int>v;
    int top = -1;
    int cap = 10;
public:
    void push(int x){
        if(isFull())return;
        top++ ;
        v.push_back(x);
        return;
    }
    void pop(){
        if(top < 0) return;
        top-- ;
        v.pop_back();
    }
    bool isEmpty(){
        return v.empty();
    }
    bool isFull(){
        if(v.size() == cap) return true;
        return false;
    }
    void display(){
        for(int i = top ; i >= 0 ; i--){
            cout<<v[i]<<"  " ;
        }
        cout<<endl;
        return;
    }
    int peak(){
        if(isEmpty())return -1;
        return v[top];
    }
    int size(){
        return v.size();
    }
};
int main(){
    stack s;
    for(int i = 0 ; i < 5 ; i++)s.push(i);
    s.display();
    s.isEmpty();
    cout<<"stack size is "<<s.size()<<endl;
    s.isFull();
    while(!s.isEmpty()){
        cout<<s.peak()<<endl;
        s.pop();
    }
}