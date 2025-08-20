#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

#define MAX_ITER 1000000
#define EPSILON 0.001

double func(double x)
{
    return x*x*x - x - 10;
}
void regulaFalsi(double x1, double x2)
{
    if (func(x1) * func(x2) >= 0) {
        cout << "You have not assumed correct x1 and x2.\n";
        return;
    }

    double x3;
    int n = 1;

    cout << fixed << setprecision(4);
    cout << "Iter\t\tx1\t\tx2\t\tx3" << endl;

    x3 = (x1 * func(x2) - x2 * func(x1)) / (func(x2) - func(x1));
    cout << n << "\t\t" << x1 << "\t\t" << x2 << "\t\t" << x3 << endl;

    while (fabs(func(x3)) >= EPSILON) {
        n++;

        if (func(x1) * func(x3) < 0)
            x2 = x3;
        else
            x1 = x3;

        x3 = (x1 * func(x2) - x2 * func(x1)) / (func(x2) - func(x1));

        cout << n << "\t\t" << x1 << "\t\t" << x2 << "\t\t" << x3 << endl;
    }

    cout << "\nThe value of root is : " << x3 << endl;
    cout << "Total iterations = " << n << endl;
}

int main()
{   double x1,x2;
    cout << "Enter initial guesses x1 and x2: ";
    cin>>x1>>x2;
    regulaFalsi(x1, x2);
    return 0;
}
