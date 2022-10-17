#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <iomanip>
#include <string.h>

using namespace std;

void straight(double Ax, double Ay, double Bx, double By);
void graphic(double* values, int n);
double get_accuracy(float x);
double simpson_runge(double a, double b);
double function(double x);

const double a = 0;
const double b = M_PI / 2.0;
const int columnwidth = 8;
const int correct_numbers = 4;	//кількість правильних цифр

int main() {

	const int n = 18;
	double values[n + 1];
	for (int i = 0; i < n + 1; i++) {
		cout << setw(columnwidth) << a + double(i) * (b - a) / double(n) << " ";
	}
	cout << endl;
	for (int i = 0; i < n + 1; i++) {
		values[i] = -simpson_runge(a, a + double(i) * (b - a) / double(n));
		cout << setw(columnwidth) << setprecision(4) << values[i] << " ";
	}
	cout << endl << endl;
	cout << "Function graph: " << endl << endl;
	graphic(values, n);

}

void straight(double Ax, double Ay, double Bx, double By) {
	double a = Ay - By;
	double b = Bx - Ax;
	double c = a * (Ax)+b * (Ay);
	cout << -a / b << "x + " << "(" << c / b << ")";
}

void graphic(double* values, int n) {
	for (int i = 0; i < n; i++) {
		cout << "Interval: " << double(i) * (b - a) / double(n) << "<x<" << double(i + 1) * (b - a) / double(n) << endl;
		cout << "f(x) = ";
		straight(double(i) * (b - a) / double(n), values[i], double(i + 1) * (b - a) / double(n), values[i + 1]);
		cout << endl << endl;
	}
}


double get_accuracy(float x) {
	double fractional_part = x - (int)(x);
	double whole_part = x - fractional_part;
	int digit = 0;
	int number_zeros = 0;
	double result = 0;
	
	if (whole_part == 0.0) {
		while (digit == 0) {
			fractional_part = fractional_part * 10;
			digit = (int)fractional_part;
			number_zeros++;
		}
		number_zeros--;
		number_zeros = number_zeros + correct_numbers;
		return result = 0.5 * pow(10, -number_zeros);
	}

	int number_int = 0;
	while (whole_part > 0) {
		number_int++;
		whole_part = whole_part / 10;
		whole_part = (int)whole_part;
	}
	return result = 0.5 * pow(10, number_int - correct_numbers);
}

double simpson_runge(double a, double b) {
	double I = 0, I_last = 0;
	int n = 2;
	int p = 4;
	double epsilon;
	double rung = 0;
	do {
		double h = (b - a) / n;
		I_last = I;
		I = function(a) + function(b);
		if (I == -0) return -I;
		if (I == 0.0) return I;
		for (int i = 1; i < n / 2 + 1; i++) {
			I += 4.0 * function((a + (2.0 * i - 1.0) * h));
		}
		for (int i = 1; i < n / 2; i++) {
			I += 2 * function((a + (2.0 * i) * h));
		}
		I *= h / 3;
		n *= 2;
		rung = abs(I - I_last) / (pow(2, p) - 1);
		epsilon = get_accuracy(I);
	} while (rung > epsilon);
	return I;
}

double function(double x) {
	return log(cos(x));
}


