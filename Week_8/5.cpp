#include <iostream>
#include<vector>

using namespace std;

int main(){
    int n = 5;
    vector<vector<pair<int,int>>> graph={
        {{1,2},{3,6}},
        {{0,2},{2,3},{3,8},{4,5}},
        {{1,3},{4,7}},
        {{0,6},{1,8}},
        {{1,5},{2,7}}
    };

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<bool> used(n, false);

    pq.push({0,0});
    cout<<"Prim's MST: \n";

    while(!pq.empty()){
        auto [w,node] = pq.top(); pq.pop();
        if(used[node]) continue;
        used[node] = true;
        cout<<node<<" ("<<w<<")\n";

        for(auto [nbr,wt] : graph[node]){
            if(!used[nbr]) pq.push({wt,nbr});
        }
    }
}
