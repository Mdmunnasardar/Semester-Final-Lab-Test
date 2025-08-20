#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

#define EPSILON 0.0001

double func(double x) {
    return x * x * x - 4*x - 10;
}

void bisection(double x1, double x2) {
    if (func(x1) * func(x2) >= 0) {
        cout << "You have not assumed correct x1 and x2.\n";
        return;
    }

    double x3;
    int n = 1;

    cout << fixed << setprecision(4);
    cout << "Iter\t\tx1\t\tx2\t\tx3" << endl;

    while ((fabs(x2 - x1) >= EPSILON)) {
        x3 = (x1 + x2) / 2;

        cout << n << "\t\t" << x1 << "\t\t"<< x2 << "\t\t"<< x3 << endl;

        if (func(x3) == 0.0)
            break;

        if (func(x1) * func(x3) < 0)
            x2 = x3;
        else
            x1 = x3;

        n++;
    }

    cout << "\nRoot of the equation = " << x3 << endl;
    cout << "Total iterations = " << n << endl;
}

int main() {
    double x1, x2;
    cout << "Enter initial guesses x1 and x2: ";
    cin >> x1 >> x2;

    bisection(x1, x2);
    return 0;
}

