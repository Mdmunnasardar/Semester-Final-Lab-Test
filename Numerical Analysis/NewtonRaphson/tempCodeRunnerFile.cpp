
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
