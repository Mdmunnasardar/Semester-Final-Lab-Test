#include <iostream>
#include <cmath>
using namespace std;

float f(float x) {
    return pow(x, 3) + x - 1;
}

void secant(float x1, float x2, float E) {
    float x0;
    int n = 0;

    cout << "Iter\t x1\t\t x2\t\t x0\n";

    if (f(x1) * f(x2) < 0) {
        do {
            x0 = (x1 * f(x2) - x2 * f(x1)) / (f(x2) - f(x1));
            cout << n + 1 << "\t " << x1 << "\t " << x2 << "\t " << x0 << endl;

            x1 = x2;
            x2 = x0;
            n++;

            if (fabs(f(x0)) < E)
                break;

        } while (fabs(x2 - x1) >= E);

        cout << "\nRoot of the given equation = " << x0 << endl;
        cout << "Number of iterations = " << n << endl;
    } else {
        cout << "Cannot find a root in the given interval.\n";
    }
}

int main() {
    float x1 = 0, x2 = 1, E = 0.0001;
    secant(x1, x2, E);
    return 0;
}
