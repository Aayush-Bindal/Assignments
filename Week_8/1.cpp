#include <iostream>
#include <vector>
using namespace std;

class Graph {
    int vertices;
    vector<vector<int>> adjMatrix;

public:
    Graph(int v) {
        vertices = v;
        adjMatrix.resize(v, vector<int>(v, 0));
    }

    void addEdge(int u, int v) {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; // undirected
    }

    void displayMatrix() {
        cout << "Adjacency Matrix:\n";
        for(int i=0;i<vertices;i++){
            for(int j=0;j<vertices;j++){
                cout<<adjMatrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    int degree(int node) {
        int count = 0;
        for(int i=0;i<vertices;i++){
            if(adjMatrix[node][i] == 1) count++;
        }
        return count;
    }

    void adjacentNodes(int node){
        cout<<"Adjacent vertices of "<<node<<" : ";
        for(int i=0;i<vertices;i++){
            if(adjMatrix[node][i] == 1)
                cout<<i<<" ";
        }
        cout<<endl;
    }
};

int main() {
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);

    g.displayMatrix();
    cout<<"Degree of 2: "<<g.degree(2)<<endl;
    g.adjacentNodes(2);

    return 0;
}
