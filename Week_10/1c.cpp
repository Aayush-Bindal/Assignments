#include <iostream>
using namespace std;

int main(){
    int arr[] = {8,5,1,4,2};
    int n = 5;

    // bubble sorting
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }

    cout<<"Bubble Sorted: ";
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}
