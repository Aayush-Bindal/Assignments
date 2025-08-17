#include <iostream>
#include <vector>
using namespace std;

int countDistinct(vector<int> arr) {
    int n = arr.size();
    int count = 0;

    for (int i = 0; i < n; i++) {
        bool isDistinct = true;
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                isDistinct = false;
                break;
            }
        }
        if (isDistinct) {
            count++;
        }
    }
    return count;
}


int main() {
    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the array elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int distinct1 = countDistinct(arr);
    cout << "Distinct elements: " << distinct1 << endl;
}
