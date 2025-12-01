#include <iostream>
using namespace std;

class PriorityQueue {
    int arr[100];
    int size;

public:
    PriorityQueue() {
        size = 0;
    }

    // Insert (push)
    void push(int value) {
        arr[size] = value;
        int i = size;
        size++;

        while(i > 0 && arr[(i-1)/2] < arr[i]) {
            swap(arr[i], arr[(i-1)/2]);
            i = (i-1)/2;
        }
    }

    // Heapify down
    void heapify(int i) {
        int largest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;

        if(left < size && arr[left] > arr[largest])
            largest = left;

        if(right < size && arr[right] > arr[largest])
            largest = right;

        if(largest != i) {
            swap(arr[i], arr[largest]);
            heapify(largest);
        }
    }

    // Remove max (pop)
    int pop() {
        if(size == 0) {
            cout << "PQ is empty!" << endl;
            return -1;
        }

        int root = arr[0];
        arr[0] = arr[size - 1];
        size--;

        heapify(0);
        return root;
    }

    // Get max
    int top() {
        if(size == 0) return -1;
        return arr[0];
    }

    bool empty() {
        return size == 0;
    }
};

int main() {
    PriorityQueue pq;

    pq.push(30);
    pq.push(10);
    pq.push(50);
    pq.push(20);
    pq.push(40);

    cout << "Top element: " << pq.top() << endl;

    cout << "Deleted: " << pq.pop() << endl;
    cout << "New Top: " << pq.top() << endl;

    cout << "Deleted: " << pq.pop() << endl;
    cout << "Deleted: " << pq.pop() << endl;

    return 0;
}
