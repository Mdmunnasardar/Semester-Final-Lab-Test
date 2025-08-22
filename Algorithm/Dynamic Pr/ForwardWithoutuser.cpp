#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int INF = INT_MAX;

void FGraphForward(vector<vector<int>>& c, int k, int n, vector<int>& path, vector<int>& cost) {
    vector<int> pred(n, -1);  // pred[i] = vertex before i on shortest path
    cost[0] = 0;              // Starting vertex has cost 0

    // Forward computation of costs
    for (int j = 1; j < n; ++j) {
        for (int i = 0; i < n; ++i) {
            if (c[i][j] != INF && cost[i] != INF && cost[j] > cost[i] + c[i][j]) {
                cost[j] = cost[i] + c[i][j];
                pred[j] = i; // record predecessor
            }
        }
    }

    // Reconstruct path from source to destination
    path[k - 1] = n - 1;  // Last vertex
    for (int i = k - 2; i >= 0; --i) {
        path[i] = pred[path[i + 1]];
    }
}

int main() {
    int n = 8;  // number of vertices
    int k = 4;  // number of stages

    // Create cost matrix and initialize with INF
    vector<vector<int>> c(n, vector<int>(n, INF));

    // Manually assign edges (source, destination, cost)
    c[0][1] = 2;
    c[0][2] = 1;
    c[1][3] = 3;
    c[1][4] = 2;
    c[2][4] = 3;
    c[2][5] = 6;
    c[3][6] = 2;
    c[4][6] = 1;
    c[5][6] = 1;
    c[6][7] = 2;

    vector<int> path(k), cost(n, INF);
    FGraphForward(c, k, n, path, cost);

    // Output results
    cout << "\nMinimum cost: " << cost[n - 1] << endl;
    cout << "Optimal path: ";
    for (int v : path) {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}