#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void dijkstra(int src, vector<vector<pair<int,int>>>& graph){
    vector<int> dist(graph.size(), INT_MAX);
    dist[src]=0;

    priority_queue<pair<int,int>, 
        vector<pair<int,int>>, greater<pair<int,int>>> pq;

    pq.push({0,src});

    while(!pq.empty()){
        auto [d,node] = pq.top(); pq.pop();

        for(auto [nbr,wt] : graph[node]){
            if(d + wt < dist[nbr]){
                dist[nbr] = d + wt;
                pq.push({dist[nbr], nbr});
            }
        }
    }

    cout<<"Shortest distances from "<<src<<":\n";
    for(int i=0;i<dist.size();i++)
        cout<<i<<" → "<<dist[i]<<endl;
}

int main(){
    vector<vector<pair<int,int>>> graph = {
        {{1,4},{2,1}},
        {{3,1}},
        {{1,2},{3,5}},
        {}
    };

    dijkstra(0, graph);
}
