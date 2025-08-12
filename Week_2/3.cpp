// we expect arr[i] = firstElement + i for a sorted arr like counting
// and if we check and doesnt match on mid then the element is on left as it has created trouble and vice versa

#include <iostream>
using namespace std;


int findMissingNumberSumMethod(int *arr, int n) {
    // The largest number should be n+1 elements total if nothing was missing
    int totalElements = arr[n - 1]; // Last element in sorted array

    // Expected sum using formula: n*(n+1)/2
    int sumExpected = (totalElements * (totalElements + 1)) / 2;

    // Actual sum of array
    int sumActual = 0;
    for (int i = 0; i < n; i++) {
        sumActual += arr[i];
    }

    // Missing number = expected - actual
    return sumExpected - sumActual;
}

int findMissingNumber(int *arr, int n) {
    int low = 0, high = n - 1;
    int first = arr[0];

    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == first + mid) {
            low = mid + 1; // missing number is on the right
        } else {
            high = mid - 1; // missing number is on the left
        }
    }
    return first + low; // missing number
}

int main() {
    int arr[] = {1, 2, 3, 4, 6, 7, 8}; // Missing 5
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Missing number: " << findMissingNumber(arr, n) << endl;
    return 0;
}
