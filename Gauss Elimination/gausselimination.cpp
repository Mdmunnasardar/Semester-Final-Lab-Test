#include <iostream>
using namespace std;

int main() {
    int i, j, k, n;
    float A[20][20], c, x[10], sum = 0.0;

    cout << "\nEnter the order of matrix: ";
    cin >> n;

    cout << "\nEnter the elements of augmented matrix row-wise:\n\n";
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n + 1; j++) {
            cout << "A[" << i << "][" << j << "] : ";
            cin >> A[i][j];
        }
    }

    // Forward elimination to upper triangular matrix
    for (j = 1; j <= n; j++) {
        for (i = 1; i <= n; i++) {
            if (i > j) {
                c = A[i][j] / A[j][j];
                for (k = 1; k <= n + 1; k++) {
                    A[i][k] = A[i][k] - c * A[j][k];
                }
            }
        }
    }

    // Backward substitution
    x[n] = A[n][n + 1] / A[n][n];
    for (i = n - 1; i >= 1; i--) {
        sum = 0;
        for (j = i + 1; j <= n; j++) {
            sum += A[i][j] * x[j];
        }
        x[i] = (A[i][n + 1] - sum) / A[i][i];
    }

    cout << "\nThe solution is: \n";
    for (i = 1; i <= n; i++) {
        cout << "\nx" << i << " = " << x[i];
    }

    return 0;
}