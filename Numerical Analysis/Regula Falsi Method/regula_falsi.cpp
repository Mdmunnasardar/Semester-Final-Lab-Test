#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

#define MAX_ITER 1000000
#define EPSILON 0.001

// Function for which we are finding root
double func(double x)
{
    return x*x*x - x - 11;
}

// Regula Falsi Method with formatted output
void regulaFalsi(double x1, double x2)
{
    if (func(x1) * func(x2) >= 0) {
        cout << "You have not assumed correct x1 and x2.\n";
        return;
    }

    double x3;
    int iter = 1;

    // Print header
    cout << fixed << setprecision(4);
    cout << "Iter\t\tx1\t\tx2\t\tx3" << endl;

    // Calculate initial x3
    x3 = (x1 * func(x2) - x2 * func(x1)) / (func(x2) - func(x1));
    cout << iter << "\t\t" << x1 << "\t\t" << x2 << "\t\t" << x3 << endl;

    while (fabs(func(x3)) >= EPSILON && iter < MAX_ITER) {
        iter++;

        // Update interval based on sign of f(x3)
        if (func(x1) * func(x3) < 0)
            x2 = x3;
        else
            x1 = x3;

        x3 = (x1 * func(x2) - x2 * func(x1)) / (func(x2) - func(x1));

        cout << iter << "\t\t" << x1 << "\t\t" << x2 << "\t\t" << x3 << endl;
    }

    cout << "\nThe value of root is : " << x3 << endl;
    cout << "Total iterations = " << iter << endl;
}

int main()
{   double x1,x2;
    cout << "Enter initial guesses x1 and x2: ";
    cin>>x1>>x2;
    regulaFalsi(x1, x2);
    return 0;
}
