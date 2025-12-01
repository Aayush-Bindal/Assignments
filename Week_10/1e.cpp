#include <iostream>
using namespace std;

int partitioning(int a[], int low, int high){
    int pivot = a[low];
    int i = low, j = high;

    while(i<j){
        while(a[i] <= pivot && i<=high) i++;
        while(a[j] > pivot && j>=low) j--;
        if(i<j) swap(a[i], a[j]);
    }
    swap(a[low], a[j]);
    return j;
}

void quick(int a[], int l, int h){
    if(l < h){
        int p = partitioning(a,l,h);
        quick(a,l,p-1);
        quick(a,p+1,h);
    }
}

int main(){
    int arr[] = {10,4,6,2,9,3};
    quick(arr,0,5);

    for(int i=0;i<6;i++) cout<<arr[i]<<" ";
}
