#include <iostream>
using namespace std;

void merge(int a[], int l, int m, int r){
    int i=l, j=m+1, k=0;
    int temp[r-l+1];

    while(i<=m && j<=r){
        temp[k++] = (a[i] < a[j]) ? a[i++] : a[j++];
    }
    while(i<=m) temp[k++] = a[i++];
    while(j<=r) temp[k++] = a[j++];

    for(int x=0; x<k; x++){
        a[l+x] = temp[x];
    }
}

void mergesort(int a[], int l, int r){
    if(l < r){
        int mid = (l+r)/2;
        mergesort(a, l, mid);
        mergesort(a, mid+1, r);
        merge(a, l, mid, r);
    }
}

int main(){
    int arr[] = {7,3,9,2,6};
    mergesort(arr,0,4);

    for(int x : arr) cout<<x<<" ";
}
