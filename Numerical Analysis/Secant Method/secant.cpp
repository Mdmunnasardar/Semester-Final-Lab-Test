#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

#define EPSILON 0.0001

// Define the function f(x)
double f(double x) {
    return x * x * x - 4 * x - 9;  // f(x) = x³ - 4x - 9
}

// Secant Method implementation with x1, x2, x3 format
void secant(double x1, double x2) {
    double x3;
    int iter = 1;

    cout << fixed << setprecision(4);
    cout << "Iter\t\tx1\t\tx2\t\tx3" << endl;

    do {
        if (f(x2) - f(x1) == 0.0) {
            cout << "Math error: Division by zero.\n";
            return;
        }

        // Secant formula
        x3 = (x1 * f(x2) - x2 * f(x1)) / (f(x2) - f(x1));

        // Display iteration
        cout << iter << "\t\t" << x1 << "\t\t" << x2 << "\t\t" << x3 << endl;

        x1 = x2;
        x2 = x3;
        iter++;
    } while (fabs(f(x3)) >= EPSILON);

    cout << "\nThe value of root is : " << x3 << endl;
    cout << "Total iterations = " << iter  << endl;
}

int main() {
    double x1, x2;
    cout << "Enter initial guesses x1 and x2: ";
    cin >> x1 >> x2;

    secant(x1, x2);

    return 0;
}
