#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Define the function f(x)
double f(double x) {
    return pow(x, 3) - x - 11;
}

// Secant Method implementation
void secant(double x1, double x2, double E) {
    double x0;
    int iter = 1;

    if (f(x1) * f(x2) >= 0) {
        cout << "Cannot find a root in the given interval [" << x1 << ", " << x2 << "]\n";
        return;
    }

    cout << fixed << setprecision(4);
    cout << "Iter\t\tx0\t\tx1\t\tx2" << endl;

    do {
        // Calculate x0 using secant formula
        x0 = (x1 * f(x2) - x2 * f(x1)) / (f(x2) - f(x1));

        // Print the current iteration
        cout << iter << "\t\t" << x1 << "\t\t" << x2 << "\t\t" << x0 << endl;

        // Check for convergence
        if (fabs(f(x0)) < E)
            break;

        // Update values for next iteration
        x1 = x2;
        x2 = x0;
        iter++;
    } while (fabs(x2 - x1) >= E);

    cout << "\nRoot of the given equation = " << x0 << endl;
    cout << "Number of iterations = " << iter << endl;
}

int main() {
    double x1 = 2, x2 = 3, E = 0.0001;
    secant(x1, x2, E);
    return 0;
}
