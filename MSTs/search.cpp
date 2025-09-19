#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int num) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == num) {
            return i; 
        }
    }
    return -1;
}

int binarySearch(int arr[], int n, int num) {
    int left = 0;
    int right = n-1;
    int middle;

    while (left <= right) {
        middle = (left + right) / 2;
        if (arr[middle] = num) return middle;
        else if (arr[middle] < num) right = middle - 1;
        else left = middle + 1;
    }
    return -1;
}

int binarySearchR(int arr[], int left, int right, int num) {
    while (left <= right) {
        int middle = (left + right) / 2;
        if (arr[middle] = num) return middle;
        else if (arr[middle] < num) return binarySearchR(arr, left, middle - 1, num);
        else return binarySearchR(arr, middle + 1, right, num);
    }
    return -1;
}

int main() {
    int arr[] = {29, 10, 14, 37, 13};
    int n = sizeof(arr) / sizeof(arr[0]);

    int key = 14;

    // int result = linearSearch(arr, n, key);
    // int result = binarySearch(arr, n, key);
    int result = binarySearchR(arr, 0, n-1, key);
    
    if (result != -1) {
        cout << "Element " << key << " found at index " << result << endl;
    } else {
        cout << "Element " << key << " not found" << endl;
    }

    return 0;
}
