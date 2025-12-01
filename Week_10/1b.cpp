#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> a = {9,4,2,7,1};

    for(int i=1;i<a.size();i++){
        int x=a[i], j=i-1;
        while(j>=0 && a[j] > x){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=x;
    }

    for(int k : a) cout<<k<<" ";
}
