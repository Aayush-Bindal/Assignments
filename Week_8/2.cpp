#include <iostream>
#include<vector>
#include<queue>
using namespace std;

void bfs(int start, vector<vector<int>>& g){
    queue<int> q;
    vector<bool> vis(g.size(), false);

    q.push(start);
    vis[start] = true;

    cout<<"BFS: ";

    while(!q.empty()){
        int node = q.front(); q.pop();
        cout<<node<<" ";

        for(int next : g[node]){
            if(!vis[next]){
                vis[next] = true;
                q.push(next);
            }
        }
    }
}

int main(){
    vector<vector<int>> graph = {
        {1,2},{0,3},{0,3},{1,2}
    };
    
    bfs(0, graph);
}
