#include<bits/stdc++.h>
using namespace std;
#define EPSILON 0.001

double func(double x)
{
	return x*x*x - x - 11;
}

void bisection(double a, double b)
{
	if (func(a) * func(b) >= 0)
	{
		cout << "You have not assumed right a and b\n";
		return;
	}

	double c;
	int iter = 1;
	cout << "Iter       a            b           f(a)        f(b)          c           f(c)" << endl;
	while ((b - a) >= EPSILON)
	{
		c = (a + b) / 2;

		cout << iter << "       "<< fixed << setprecision(6) << a << "    "<< b << "    "<< func(a) << "    "<< func(b) << "    "<< c << "    "<< func(c) << endl;

		if (func(c) == 0.0)
			break;

		else if (func(c) * func(a) < 0)
			b = c;
		else
			a = c;

		iter++;
	}
	cout << "The value of the root is: " << fixed << setprecision(6) << c << endl;
}

int main()
{
	double a, b;
	cout << "Enter the value of a: ";
	cin >> a;
	cout << "Enter the value of b: ";
	cin >> b;
	bisection(a, b);
	return 0;
}
