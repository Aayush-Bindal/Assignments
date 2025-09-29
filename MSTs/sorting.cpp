#include <iostream>
#include <algorithm>
using namespace std;

void selectionSort(int *arr, int n) {
    int min;
    for (int i = 0; i < n-1; i++) {
        min = i;
        for (int j = i; j < n; j++) {
            if (arr[min] > arr [j]) {
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        bool isSwapped = 0;
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                isSwapped = 1;
            }
        }
        if (!isSwapped) {
            break;
        }
    }
}

void bubbleSortR(int arr[], int n) {
    if (n == 0) {
        return;
    }
    int count = 0;

    for (int i = 0; i < n-1; i++) {
        if (arr[i] > arr[i+1]) {
            swap(arr[i], arr[i+1]);
            count++;
        }
    }

    if (!count) {
        return;
    }

    bubbleSortR(arr, n-1);
}

void insertionSort(int arr[], int n) {
    for (int i = 0; i < n ; i++) {
        int j = i;
        while (j > 0 && arr[j-1] > arr[j]) {
            swap(arr[j-1], arr[j]);
            j--;
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main() {
    int arr[] = {29, 10, 14, 37, 13};
    int size = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, size);
    // selectionSort(arr, size); //BigO(n2)
    // bubbleSort(arr, size); //BigO(n2) Bigw(n)
    // insertionSort(arr, size); //BigO(n2) Bigw(n)
    bubbleSortR(arr, size);
    printArray(arr, size);

    return 0;
}