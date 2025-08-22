#include <iostream>
#include <vector>
using namespace std;

const int INF = 100000000;

// Function to compute all-pairs shortest paths
void floydWarshall(vector<vector<int>> &dist) {
    int V = dist.size();
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

// Function to print the distance matrix
void printDistanceMatrix(const vector<vector<int>> &dist) {
    int V = dist.size();
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF) cout << "INF ";
            else cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;

    vector<vector<int>> dist(V, vector<int>(V));

    cout << "Enter adjacency matrix (use " << INF << " for no edge):\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> dist[i][j];
        }
    }

    floydWarshall(dist);                  // Compute shortest paths
    cout << "\nAll-pairs shortest distance matrix:\n";
    printDistanceMatrix(dist);            // Print the result

    return 0;
}
