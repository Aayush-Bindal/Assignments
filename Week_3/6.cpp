#include <iostream>
using namespace std;

struct Triplet {
    int row, col, value;
};

void transpose(Triplet arr[], int &size, int totalRows, int totalCols) {
    Triplet temp;
    for (int i = 0; i < size; i++) {
        temp = arr[i];
        arr[i].row = temp.col;
        arr[i].col = temp.row;
    }
}

void add(Triplet arr1[], Triplet arr2[], Triplet result[], int size1, int size2, int &resultSize) {
    int i = 0, j = 0, k = 0;
    while (i < size1 && j < size2) {
        if (arr1[i].row < arr2[j].row || (arr1[i].row == arr2[j].row && arr1[i].col < arr2[j].col)) {
            result[k++] = arr1[i++];
        } else if (arr1[i].row > arr2[j].row || (arr1[i].row == arr2[j].row && arr1[i].col > arr2[j].col)) {
            result[k++] = arr2[j++];
        } else {
            result[k] = arr1[i];
            result[k].value += arr2[j].value;
            i++;
            j++;
            k++;
        }
    }
    while (i < size1) result[k++] = arr1[i++];
    while (j < size2) result[k++] = arr2[j++];
    resultSize = k;
}

void multiply(Triplet arr1[], Triplet arr2[], Triplet result[], int size1, int size2, int &resultSize, int totalRows, int totalCols) {
    int k = 0;
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            if (arr1[i].col == arr2[j].row) {
                bool found = false;
                for (int m = 0; m < k; m++) {
                    if (result[m].row == arr1[i].row && result[m].col == arr2[j].col) {
                        result[m].value += arr1[i].value * arr2[j].value;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    result[k].row = arr1[i].row;
                    result[k].col = arr2[j].col;
                    result[k].value = arr1[i].value * arr2[j].value;
                    k++;
                }
            }
        }
    }
    resultSize = k;
}

int main() {
    int rows, cols, size1, size2;
    cout << "Enter number of rows and columns for the matrices: ";
    cin >> rows >> cols;

    cout << "Enter number of non-zero elements in matrix 1: ";
    cin >> size1;
    Triplet arr1[size1];
    cout << "Enter the non-zero elements in matrix 1 (row, column, value): \n";
    for (int i = 0; i < size1; i++) {
        cin >> arr1[i].row >> arr1[i].col >> arr1[i].value;
    }

    cout << "Enter number of non-zero elements in matrix 2: ";
    cin >> size2;
    Triplet arr2[size2];
    cout << "Enter the non-zero elements in matrix 2 (row, column, value): \n";
    for (int i = 0; i < size2; i++) {
        cin >> arr2[i].row >> arr2[i].col >> arr2[i].value;
    }

    Triplet result[100];
    int resultSize;

    cout << "Transpose of matrix 1: \n";
    transpose(arr1, size1, rows, cols);
    for (int i = 0; i < size1; i++) {
        cout << arr1[i].row << " " << arr1[i].col << " " << arr1[i].value << "\n";
    }

    cout << "Addition of matrices: \n";
    add(arr1, arr2, result, size1, size2, resultSize);
    for (int i = 0; i < resultSize; i++) {
        cout << result[i].row << " " << result[i].col << " " << result[i].value << "\n";
    }

    cout << "Multiplication of matrices: \n";
    multiply(arr1, arr2, result, size1, size2, resultSize, rows, cols);
    for (int i = 0; i < resultSize; i++) {
        cout << result[i].row << " " << result[i].col << " " << result[i].value << "\n";
    }

    return 0;
}
