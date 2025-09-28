#include <iostream>
using namespace std;

class Node{
    public:
    Node* next ;
    int val;
    Node(){

    }
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
    void push_back(int val){
        Node* newNode = new Node(val);
        Node*temp = head;
        if(head == NULL){
            head = newNode;
            return;
        }
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
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
// finding middle of list : using fast and slow pointer
    Node* middle(Node* head){
        Node* slow = head;
        Node* fast = head;
        while (fast->next != NULL || fast!= NULL  )
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
int main(){
    SLL List;
    for(int i = 0 ; i < 10 ; i++)List.push_back(i);
    List.display();
    Node* mid = new Node(middle(List.head)->val);
    cout<<endl<<mid->val;
}