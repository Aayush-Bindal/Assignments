#include <iostream>
#include<vector>

using namespace std;

struct Edge { int u, v, w; };

int findParent(int x, vector<int>& p){
    if(p[x] == x) return x;
    return p[x] = findParent(p[x], p);
}

int main(){
    vector<Edge> edges = {
        {0,1,10},{0,2,6},{0,3,5},{1,3,15},{2,3,4}
    };

    sort(edges.begin(), edges.end(), [](auto &a, auto &b){
        return a.w < b.w;
    });

    vector<int> parent(4);
    for(int i=0;i<4;i++) parent[i]=i;

    cout<<"Kruskal's MST Edges:\n";

    for(auto &e : edges){
        int pu = findParent(e.u,parent);
        int pv = findParent(e.v,parent);

        if(pu != pv){
            cout<<e.u<<" - "<<e.v<<" ("<<e.w<<")\n";
            parent[pu] = pv;
        }
    }
}
