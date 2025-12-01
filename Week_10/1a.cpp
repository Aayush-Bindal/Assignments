#include <iostream>
using namespace std;

int main(){
    int arr[] = {5,2,9,1,3};
    int n = 5;

    for(int i = 0; i < n-1; i++){
        int pos = i;
        for(int j = i+1; j < n; j++){
            if(arr[j] < arr[pos]){
                pos = j;
            }
        }
        swap(arr[i], arr[pos]);
    }

    cout<<"Selection Sorted: ";
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}
