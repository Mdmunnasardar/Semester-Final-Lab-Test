#include <bits/stdc++.h>
using namespace std;
double func(double x)
{
    return x * x * x - 4 * x - 9;
}
void SecantMethod(double a, double b)
{
    double c;
    int iter = 1;

    cout << fixed << setprecision(4);
    cout << "Iter\t\tx0\t\tx1\t\tx2\n";
    while (true)
    {
        if (func(a)-func(b) == 0)
        {
            cout << "Cannot divide by zero";
            return;
        }
        c = ((a * func(b)) - (b * func(a))) / (func(b) - func(a));
        cout << iter << "\t\t" << a << "\t\t" << b << "\t\t" << c << endl;
        if (fabs(b - a) < 0.0001)
            break;

        a = b;
        b = c;
        iter++;
    }
    cout << "\nThe value of the root is: " << c << endl;
}
int main()
{
    double a = 1, b = 5;
    SecantMethod(a, b);
    return 0;
}