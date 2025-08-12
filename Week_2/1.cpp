#include <iostream>
using namespace std;

int binarySearch1(int *array, int x, int low, int high) {

    // Repeat until the pointers low and high meet each other
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (x == array[mid])
            return mid;

        if (x > array[mid])
            low = mid + 1;

        else
            high = mid - 1;
    }

    return -1;
}

int binarySearch2(int array[], int x, int low, int high) {
    if (high >= low) {
        int mid = low + (high - low) / 2;

        // If found at mid, then return it
        if (x == array[mid])
            return mid;

        // Search the right half
        if (x > array[mid])
            return binarySearch2(array, x, mid + 1, high);

        // Search the right half
        return binarySearch2(array, x, low, mid - 1);
    }

    return -1;
}

int main() {
    int array[] = {3, 4, 5, 6, 7, 8, 9};
    int x = 4;
    int n = sizeof(array) / sizeof(array[0]);
    int result = binarySearch2(array, x, 0, n - 1);
    if (result == -1)
        printf("Not found");
    else
        printf("Element is found at index %d", result);
}