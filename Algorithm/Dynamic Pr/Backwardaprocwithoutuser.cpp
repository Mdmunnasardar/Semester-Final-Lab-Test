#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int INF = INT_MAX;

void FGraph(vector<vector<int>>& c, int k, int n, vector<int>& path, vector<int>& cost) {
    vector<int> d(n, -1);     // d[i] = next vertex on the shortest path from i
    cost[n - 1] = 0;          // Cost to reach destination is 0

    // Backward computation of costs
    for (int j = n - 2; j >= 0; --j) {
        for (int i = 0; i < n; ++i) {  // replaced r with i
            if (c[j][i] != INF && cost[i] != INF && cost[j] > c[j][i] + cost[i]) {
                cost[j] = c[j][i] + cost[i];
                d[j] = i;
            }
        }
    }

    // Reconstruct the path
    path[0] = 0;
    path[k - 1] = n - 1;
    for (int j = 1; j < k - 1; ++j) {
        path[j] = d[path[j - 1]];
    }
}

int main() {
    int n = 8; // number of vertices
    int k = 4; // number of stages

    vector<vector<int>> c(n, vector<int>(n, INF));

    // Manually assigning edges (source, destination, cost)
    c[0][1] = 1;
    c[0][2] = 2;
    c[1][3] = 3;
    c[1][4] = 4;
    c[2][4] = 2;
    c[2][5] = 3;
    c[3][6] = 6;
    c[4][6] = 1;
    c[5][6] = 5;
    c[6][7] = 2;

    vector<int> path(k);
    vector<int> cost(n, INF);
    FGraph(c, k, n, path, cost);

    cout << "\nMinimum cost: " << cost[0] << endl;
    cout << "Optimal path: ";
    for (int stage : path) {
        cout << stage << " ";
    }
    cout << endl;

    return 0;
}