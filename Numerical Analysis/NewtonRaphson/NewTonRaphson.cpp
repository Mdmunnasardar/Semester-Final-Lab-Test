// C++ program for implementation of Newton Raphson Method for
// solving equations
#include <bits/stdc++.h>
#define EPSILON 0.0001
using namespace std;

// Function: f(x) = x^3 - x - 9
double func(double x)
{
	return x * x * x - x - 10;
}

// Derivative: f'(x) = 3x^2
double derivFunc(double x)
{
	return 3 * x * x;
}

// Function to find the root using Newton-Raphson
void newtonRaphson(double x)
{
	double h = func(x) / derivFunc(x);
	int iter = 1;

	cout << fixed << setprecision(4);
	cout << "Iter\t\tx1\t\tx2" << endl;

	while (abs(h) >= EPSILON)
	{
		h = func(x) / derivFunc(x);
		double x2 = x - h;

		cout << iter << "\t\t" << x << "\t\t" << x2 << endl;

		x = x2;
		iter++;
	}

	cout << "\nThe value of the root is : " << x << endl;
	cout << "Total iterations = " << iter - 1 << endl;
}

// Main driver
int main()
{
	double x0 ;
	cout<<"Enter the Number: ";
	cin>>x0;
	newtonRaphson(x0);
	return 0;
}
