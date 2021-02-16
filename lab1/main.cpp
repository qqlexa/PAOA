#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

double power(double number, int pow) {
	double result = 1;

	if (number == 0) {
		if (pow == 0) {
			result = 1;
		}
		else {
			if (pow < 0) {
				cout << "Error" << endl;
			}
			result = 0;
		}
	}
	else {
		if (pow == 0) {
			result = 1;
		}
		else {
			for (int i = 0; i < abs(pow); i++) {
				result *= number;
			}
			if (pow < 0) {
				result = 1 / result;
			}
		}
	}
	return result;
}
/*
int main() {
	double result, currently_sum, a;
	float eps = 0.0001;
	int b, n;
	cout << "Enter a = ";
	cin >> a;
	cout << left <<
		setw(7) << "x" <<
		setw(15) << "sum by while" <<
		setw(15) << "(a^x)/x" <<
		setw(6) << "iters" << endl;

	for (double x = -10; x <= 10; x += 0.25) {
		result = 0;
		currently_sum = 0;
		n = 0;
		do {
			currently_sum = power(x, n - 1);

			b = 1;
			while (b <= n) {
				currently_sum *= log(a) / b;
				b++;
			}

			result += currently_sum;
			n++;
		} while (eps < abs(currently_sum));

		cout << 
			setw(7) << x <<
			setw(15) << result <<
			setw(15) << pow(a, x) / x <<
			setw(6) << n <<
			endl;
	}
	return 0;
}
*/

int main() {
	double result, currently_sum, a;
	int b;
	cout << "Enter a = ";
	cin >> a;
	double x = -10;
	cout << left <<
		setw(7) << "x" <<
		setw(15) << "sum" <<
		setw(15) << "(a^x)/x" <<
		setw(6) << "iters" << endl;

	while (x <= 10) {

		result = 0;
		currently_sum = 0;

		for (int n = 0; n <= 100; n++) {
			currently_sum = power(x, n - 1);

			b = 1;
			while (b <= n) {
				currently_sum *= log(a) / b;
				b++;
			}

			result += currently_sum;
		}
		cout <<
			setw(7) << x <<
			setw(15) << result <<
			setw(15) << pow(a, x) / x <<
			setw(6) << 100 <<
			endl;
		x += 0.25;
	}
	return 0;
}
