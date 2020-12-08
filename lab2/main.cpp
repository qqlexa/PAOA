// 6.	Видалити з масиву додатні елементи, змістивши на їх місце попередні елементи
// Не було обмежень на створення додаткового масиву, але вирішив зробити в двох варіантах

#include <iostream>
#include <ctime>

using namespace std;

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

int main() {
	int n, m;               // first / second arrays indexes 
	int k = 0;              // count of positive numbers
	cin >> n;
	int* arr = new int[n];
	srand(time(0));
	for (int i = 0; i < n; i++) {
		*(arr + i) = rand() % 9 - 4;
		cout << *(arr + i) << " ";
	}
	cout << endl;

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
	m = n - k;

	cut_elements(arr, m);
	for (int i = 0; i < m; i++) {
		cout << *(arr + i) << " ";
	}

	cout << endl;
	cout << "Number of elements in array = " << n << endl;
	cout << "Value of positive elements = " << k << endl;
	cout << "Value of array without positive elements = " << m << endl;
	delete[] arr;
	return 1;
}
