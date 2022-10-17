#include <iostream>
#include <cmath>
#include <iomanip>
#include <string.h>

using namespace std;

const double a = 1;
const double b = 7;

double function(double x) {
	return atan(x) / (1 + pow(x, 3));
}

double simpson_runge(double a, double b) {
	double I = 0, I_last = 0;
	int n = 2;
	int p = 4;
	double epsilon = 0.000001;
	double rung = 0;
	int st = 0;
	cout << "Epsilon = 0.0001" << endl << endl;
	do {
		st++;
		double h = (b - a) / n;
		I_last = I;
		I = function(a) + function(b);
		for (int i = 1; i < n / 2 + 1; i++) {
			I += 4.0 * function((a + (2.0 * i - 1.0) * h));
		}
		for (int i = 1; i < n / 2; i++) {
			I += 2 * function((a + (2.0 * i) * h));
		}
		I *= h/3;
		cout << "Step " << st << ":" << endl << "Integral with h/" << n << " equels " << I << ";" << endl << endl;
		n *= 2;
		rung = abs(I - I_last) / (pow(2, p) - 1);
	} while (rung > epsilon);
	return I;
}

int main()
{
	cout << endl << "Result:" << endl << "I = " << simpson_runge(a, b);
	return 0;
}
