#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9; // A large value representing no edge

void floydWarshall(vector<vector<int>> &dist) {
    int V = dist.size();

    for (int k = 0; k < V; k++)
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                if (dist[i][k] < INF && dist[k][j] < INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    // Detect negative cycles
    for (int i = 0; i < V; i++) {
        if (dist[i][i] < 0) {
            cout << "Graph contains a negative weight cycle!\n";
            return;
        }
    }
}

int main() {
    vector<vector<int>> dist = {
        {0,   4, INF, 5,   INF},
        {INF, 0, 1,   INF, 6},
        {2,   INF, 0, 3,   INF},
        {INF, INF, 1, 0,   2},
        {1,   INF, INF, 4, 0}
    };

    floydWarshall(dist);

    cout << "All-pairs shortest path distances:\n";
    for (int i = 0; i < dist.size(); i++) {
        for (int j = 0; j < dist.size(); j++) {
            if (dist[i][j] == INF) cout << "INF ";
            else cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
}
