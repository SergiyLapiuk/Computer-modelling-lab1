#include <iostream>
#include <cmath>
#include <iomanip>
#include <string.h>

using namespace std;

const double a = 0.01;
const double b = 1;

double function(double x) {
	return 1 / (sqrt(x * (1 + x*x )));
}

double trapeze_runge(double a, double b) {
	double I = 0, I_last = 0;
	int n = 2;
	int p = 2;
	double epsilon = 0.3;
	double rung = 0;
	do {
		double h = (b - a) / n;
		I_last = I;
		I = function(a) / 2 + function(b) / 2;
		for (int i = 1; i < n; i++) {
			I += function((a + i * h));
		}
		I *= h;
		cout << "Integral with h/" << n << " equels " << I << ";" << endl;
		n *= 2;
		rung = abs(I - I_last) / (pow(2, p) - 1);
	} while (rung > epsilon);
	return I;
}

int main()
{
    cout << endl << "Result:" << endl << "I_2 = " << trapeze_runge(a, b);
	return 0;
}
