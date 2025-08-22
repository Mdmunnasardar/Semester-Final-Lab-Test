#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

const int MAX = 100; // max number of vertices

class Solution {
public:
    void spanningTree(int V, int adj[MAX][MAX]) {
        vector<int> key(V, INT_MAX);     // Minimum weight to include a vertex
        vector<int> parent(V, -1);       // Parent of each vertex in MST
        vector<bool> visited(V, false);  // Tracks vertices included in MST

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

        key[0] = 0;       // Start from vertex 0
        pq.push({0, 0});  // {weight, vertex}

        int totalWeight = 0;

        while(!pq.empty()) {
            
            int wt = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if(visited[u]) continue;
            visited[u] = true;
            totalWeight += wt;

            if(parent[u] != -1)
                cout << parent[u] << " - " << u << " : " << wt << "\n";

            for(int v = 0; v < V; v++) {
                if(adj[u][v] != 0 && !visited[v] && adj[u][v] < key[v]) {
                    key[v] = adj[u][v];
                    parent[v] = u;
                    pq.push({key[v], v});
                }
            }
        }

        cout << "Total weight of MST: " << totalWeight << endl;
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    int adj[MAX][MAX] = {0};

    cout << "Enter edges (source destination weight):" << endl;
    for(int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u][v] = w;
        adj[v][u] = w; // undirected graph
    }

    Solution obj;
    cout << "Edges in MST:\n";
    cout << "------------------\n";
    obj.spanningTree(V, adj);

    return 0;
}
