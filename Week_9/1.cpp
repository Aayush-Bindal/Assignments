#include <iostream>
using namespace std;

void maxHeapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[left] > arr[largest])
        largest = left;

    if(right < n && arr[right] > arr[largest])
        largest = right;

    if(largest != i) {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void minHeapify(int arr[], int n, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[left] < arr[smallest])
        smallest = left;

    if(right < n && arr[right] < arr[smallest])
        smallest = right;

    if(smallest != i) {
        swap(arr[i], arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

void heapSortIncreasing(int arr[], int n) {
    for(int i = n/2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);

    for(int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        maxHeapify(arr, i, 0);
    }
}

void heapSortDecreasing(int arr[], int n) {
    for(int i = n/2 - 1; i >= 0; i--)
        minHeapify(arr, n, i);

    for(int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        minHeapify(arr, i, 0);
    }
}

int main() {
    int arr1[] = {12, 11, 13, 5, 6, 7};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);

    heapSortIncreasing(arr1, n1);
    cout << "Heapsort Increasing Order: ";
    for(int i = 0; i < n1; i++)
        cout << arr1[i] << " ";
    cout << endl;

    int arr2[] = {12, 11, 13, 5, 6, 7};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);

    heapSortDecreasing(arr2, n2);
    cout << "Heapsort Decreasing Order: ";
    for(int i = 0; i < n2; i++)
        cout << arr2[i] << " ";
    cout << endl;

    return 0;
}
