#include <iostream>
using namespace std;

class Node{
    public:
    Node* next ;
    int val;
    Node(int num){
        val = num;
        next = NULL;
    }
};
class SLL{
   public:
    Node* head;
    SLL(){
        head = NULL;
    }
    void push_front(int val){
        Node* temp = head;
        Node* newNode = new Node(val);
        head = newNode;
        head->next = temp;
    }
    Node* reverse(){
        Node* temp = head;
        Node* prev = NULL;
        Node* next = NULL;
        while(temp!= NULL){
            next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        head = prev;
        return prev;
    }
    void display(){
        Node*temp = head;
        while(temp!= NULL){
            cout<<temp->val<<"->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
        return;
    }
};
int main(){
    SLL V;
    for(int i = 0 ; i < 2; i++)
    V.push_front(i);
    V.display();
    // reversing list
    V.reverse();
    V.display();
    return 0;
}