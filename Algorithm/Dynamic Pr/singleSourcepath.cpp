#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int INF = INT_MAX;

void BellmanFord(int source, vector<vector<int>>& cost, vector<int>& dist, int n) {
    // Initialize distances from source to INF, except source itself
    for (int i = 0; i < n; ++i) {
        dist[i] = INF;
    }
    dist[source] = 0;

    // Relax edges up to (n-1) times
    for (int k = 1; k <= n - 1; ++k) {
        for (int u = 0; u < n; ++u) {
            for (int v = 0; v < n; ++v) {
                if (cost[u][v] != INF && dist[u] != INF && dist[v] > dist[u] + cost[u][v]) {
                    dist[v] = dist[u] + cost[u][v];
                }
            }
        }
    }
}

int main() {
    int n, source;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the source vertex (0 to " << n - 1 << "): ";
    cin >> source;

    vector<vector<int>> cost(n, vector<int>(n, INF));
    cout << "Enter the cost matrix (use large number or INT_MAX for no edge):" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> cost[i][j];
        }
    }

    vector<int> dist(n, INF);
    BellmanFord(source, cost, dist, n);

    cout << "Shortest distances from vertex " << source << ":\n";
    for (int i = 0; i < n; ++i) {
        if (dist[i] == INF) {
            cout << "Vertex " << i << ": INF (no path)\n";
        } else {
            cout << "Vertex " << i << ": " << dist[i] << "\n";
        }
    }

    return 0;
}