#include <iostream>
using namespace std;

#define MAX_SIZE 5

class circularQueue {
public:
    int front;
    int rear;
    int arr[MAX_SIZE];

    circularQueue(): front(-1), rear(-1) {}

    bool isEmpty() {
        return front == -1; 
    }

    bool isFull() {
        return (rear + 1) % MAX_SIZE == front; 
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }

    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue is full" << endl;
            return;
        }
        
        if (isEmpty()){
            front = rear = 0;
        } else rear = (rear + 1) % MAX_SIZE;

        arr[rear] = val;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        int ans = arr[front];
        
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }

        return ans;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue:  ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % MAX_SIZE;
        }
        cout << endl;
    }
};

int main() {
    circularQueue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    q.display();
    cout << "Front element: " << q.peek() << endl;

    q.enqueue(4);
    q.enqueue(5);
    
    cout << "Remove: " << q.dequeue() << endl;

    q.display();

    q.enqueue(6);
    
    q.display();

    cout << "Remove: " << q.dequeue() << endl;

    q.display();
    cout << "Front element: " << q.peek() << endl;


    return 0;
}