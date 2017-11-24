#include <iostream>

using namespace std;


/* ​Реализуйте​ ​шаблонные​ ​функции​ ​для​ ​поиска​ ​максимума,​ ​минимума,​
​сортировки​ ​массива (любым​ ​алгоритмом​ ​сортировки),​
​поиска​ ​в​ ​массиве,​ ​замены​ ​элемента​ ​массива​ ​на переданное​ ​значение. */

template <typename T>  // Search min
T getMinOfArrayElemint(T a[], int size) {
	if (size < 1) {
		cout << "Array is empty";
	}
	T min = a[0];
	for (int i = 0; i < size; i++)
	{
		if (a[i] < min) {
			min = a[i];
		}
	}
	return min;
}

template <typename T> // Search max
T getMAXOfArrayElemint(T a[], int size) {
	if (size < 1) {
		cout << "Array is empty";
	}
	T max = a[0];
	for (int i = 0; i < size; i++)
	{
		if (a[i] > max) {
			max = a[i];
		}
	}
	return max;
}

template <typename T>
void quicksort(T a[], int size) { // Sort
	if (size < 1) {
		cout << "Array is empty";
	}
	for (int j = 0; j < size; ++j) {
		for (int i = 0; i < size - 1; ++i) {
			if (a[i] > a[i + 1]) {
				swap(a[i], a[i + 1]);
			}
		}
	}
	for (int i = 0; i < size; ++i){
		cout << a[i] << " ";
	}
}


template <typename T> // replacement
void getRepfArrayElemint(T a[], int x, int num, int size) {
	if (size < 1) {
		cout << "Array is empty";
	}
	cout << endl;
	for (int i = 0; i < size; ++i){
		cout << a[i] << " ";
	}
	cout << endl;
	cout << "The number is: " << x << endl;
	
	for (int i = 0; i < size; i++)
	{
		if (a[i] == a[num]) {
			a[i] = x;
		}
	}
	for (int i = 0; i < size; ++i)
	{
		cout << a[i] << " ";
	}
}

template <typename T>
T getfinedOfArrayElemint(T a[], int x, int size) { // Search
	if (size < 1) {
		cout << "Array is empty";
	}

	for (int i = 0; i < size; i++)
	{
		if (a[i] == x) {
			cout << endl;
			cout << "your number is  " << x << endl;
		}
	}	
	return x;
}


int main() {

	int a[5] = { 10,22,13,4,15 };
	cout << "min " << getMinOfArrayElemint(a, 5) << endl;
	cout << "max " << getMAXOfArrayElemint(a, 5) << endl;

	quicksort(a, 5);
	getfinedOfArrayElemint(a, 22, 5);
	getRepfArrayElemint(a, 88, 3, 5);
	system("pause");
	return 0;
}