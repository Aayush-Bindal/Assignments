#include <iostream>
using namespace std;

int main(){
    int arr[] = {9,2,7,1,6,3};
    int n = 6;

    int start = 0, end = n-1;

    while(start < end){
        int minIndex = start;
        int maxIndex = end;

        for(int i = start; i <= end; i++){
            if(arr[i] < arr[minIndex]) minIndex = i;
            if(arr[i] > arr[maxIndex]) maxIndex = i;
        }

        swap(arr[start], arr[minIndex]);

        // if we swapped earlier maxIndex position, correct it
        if(maxIndex == start) maxIndex = minIndex;

        swap(arr[end], arr[maxIndex]);

        start++;
        end--;
    }

    cout<<"Improved Selection Sort: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
