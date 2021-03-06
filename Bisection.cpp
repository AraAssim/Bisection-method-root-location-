//Bisection (interval halving) method 
#include <iostream>
#include<iomanip>
#include <cmath>
using namespace std;
long double fun(long double x)
{
	// Please enter the function here
	return (2 * pow(x, 2)) + (3 * exp(-x));
}
long double dichotomous(long double& a, long double& b, const long double& i, long double& L)
{
	long double x1 = a + (b - a) / 4;
	long double x2 = b - (b - a) / 4;
	long double xm = (b + a) / 2;
	while (L > i) {
		if (fun(x1) < fun(xm)) {
			b = xm;
			xm = x1;
			x1 = a + (b - a) / 4;
			x2 = b - (b - a) / 4;
		}
		else if (fun(x2) < fun(xm)) {
			a = xm;
			xm = x2;
			x1 = a + (b - a) / 4;
			x2 = b - (b - a) / 4;
		}
		else {
			a = x1;
			b = x2;
			x1 = a + (b - a) / 4;
			x2 = b - (b - a) / 4;
		}
		L = b - a;
	}
	return xm;
}
int main() {
	// Please insert the values of a & b to define an interval, and the error rate (i).
	long double a = 0, b = 1, L = b - a, i = 0.000000000001;

	cout << "The value of x is " << setprecision(10) << dichotomous(a, b, i, L) << endl;
	cout << "The value of y is " << setprecision(10) << fun(dichotomous(a, b, i, L)) << endl;
	cout << "For an error rate of = " << i << endl;
std:cin.get();
	return 0;
}
