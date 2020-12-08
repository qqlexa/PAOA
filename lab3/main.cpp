#include <iostream>
#include <ctime>

using namespace std;

void print_arr(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		cout << *(arr + i) << " ";
	}
	cout << endl;
}

int* init_arr(int* arr, int n) {
	srand(time(0));
	for (int i = 0; i < n; i++) {
		*(arr + i) = rand() % 9 - 4;
		cout << *(arr + i) << " ";
	}
	cout << endl;
	return arr;
}

void cut_elements(int*& arr, int m) {
	int* new_arr = new int[m];

	for (int i = 0; i < m; i++) {
		*(new_arr + i) = *(arr + i);
	}

	delete[] arr;
	arr = new_arr;

	new_arr = NULL;
	delete[] new_arr;
}

int delete_positives(int* arr, int n) {
	int k = 0;
	for (int i = 0; i < n - k;) {
		if (*(arr + i) > 0) {
			for (int j = i; j < n - k - 1; j++) {
				*(arr + j) = *(arr + j + 1);
			}
			k++;
		}
		else {
			i++;
		}
	}
	return n - k;
}

// func range() from python
int* range(int a, int b, int step = 1) {
	int m = float(b - a) / step;
	cout << "int m = " << m << endl;

	int* arr = new int[m];
	int counter = a;
	for (int i = 0; i < m; i++) {
		*(arr + i) = counter;
		cout << *(arr + i) << " ";
		counter += step;
	}
	cout << endl;

	return arr;
}


float* range(float a, float b, float step = 0.1) {
	int m = (b - a) / step;
	cout << "float m = " << m << endl;

	float* arr = new float[m];
	float counter = a;
	for (int i = 0; i < m; i++) {
		*(arr + i) = counter;
		cout << *(arr + i) << " ";
		counter += step;
	}
	cout << endl;

	return arr;
}

double* range(double a, double b, double step = 0.1) {
	int m = (b - a) / step;
	cout << "double m = " << m << endl;

	double* arr = new double[m];
	double counter = a;
	for (int i = 0; i < m; i++) {
		*(arr + i) = counter;
		cout << *(arr + i) << " ";
		counter += step;
	}
	cout << endl;

	return arr;
}

int main() {
	int n;
	cin >> n;
	int* arr = new int[n];
	arr = init_arr(arr, n);

	n = delete_positives(arr, n);
	cut_elements(arr, n);
	print_arr(arr, n);

	delete[] arr;

	/*
	range(1, 5, 3);
	range(1, 3, 1);
	range(1.0f, 3.0f, 1.5f);
	range(1.0, 3.0, 1.005);
	*/
	return 1;
}
