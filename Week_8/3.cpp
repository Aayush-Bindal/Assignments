#include <iostream>
#include <vector>
using namespace std;

void dfs(int v, vector<vector<int>>& edges, vector<bool>& visited){
    visited[v] = true;
    cout << v << " ";

    for(int nbr : edges[v]){
        if(!visited[nbr])
            dfs(nbr, edges, visited);
    }
}

int main(){
    vector<vector<int>> adj = {
        {1,2},
        {0,3},
        {0,3},
        {1,2}
    };

    vector<bool> seen(adj.size(), false);
    cout<<"DFS: ";
    dfs(0, adj, seen);
}
