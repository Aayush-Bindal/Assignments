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
    // insertion at begining
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
        if(head == NULL) {
            head = newNode;
            return;
        }
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    void pop_front(){
        if(head == NULL)return;
        else if(head->next == NULL){
            delete head;
            head = NULL;
        }
        else{
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
    }
    void insert(int val , int idx){
        Node* newNode = new Node(val);
        if(idx == 0){
            push_front(val);
            return;
        }
        Node * temp = head;
        
        for(int i = 0 ; i < idx-1 && temp != NULL; i++){
            temp = temp->next;
        }
        // now temp points to just previous element of required index
        cout<<temp->val<<endl;
        if(temp == NULL) {
        cout << "Index out of bounds\n";
        delete newNode;
        return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        return;
    }
    void pop_back() {
        if(head == NULL) return;
        if(head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }
        Node* temp = head;
        Node* prev = NULL;
        while(temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        delete temp;
    }
    Node* deleteNode(int x) { // assuming indexing from 0
         Node* temp = head;
         Node* prev = NULL;
         if(x == 0){
             Node* temp = head;
             head = head->next;
             delete temp;
             return head;
         }
        for(int i = 0 ; i < x && temp != NULL ; i++){
            prev = temp;
            temp = temp->next;
        }
        if(temp == NULL){
            return head;
        }
        prev->next = temp->next;
        delete temp;
    return head;
    }
    int search(int value){
        int count = 0;
        Node* temp = head;
        while(temp!= NULL && temp->val != value){
            temp = temp->next;
            count++;
        }
        return (temp == NULL)? -1 : count;
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
    SLL list;
    list.push_back(10);
    list.push_back(20);
    list.push_front(5);
    list.display(); // 5->10->20->NULL
    list.insert(15, 2);
    list.display(); // 5->10->15->20->NULL
    list.deleteNode(1);
    list.display(); // 5->15->20->NULL
    cout<< "15 is at "<<list.search(15)<<"th index"<<endl; //  15 is at 1th index
}