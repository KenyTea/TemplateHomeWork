
#include "stdafx.h"




template<typename T>
class Matrix {
public:
	T **arr;
	int height, width;

	Matrix(int height, int width) 
	{
		this->height = height;
		this->width = width;
		arr = new T*[width];
		for (int i = 0; i < width; i++) {
			arr[i] = new T[height];
		}
		for (int j = 0; j < width; ++j)
			for (int k = 0; k < height; ++k)
				arr[j][k] = rand() % 10;

	}



	~Matrix() {
		for (int i = 0; i < width; i++) {
			delete	arr[i];
		}
		delete arr;
	}

	void Print();

	};


	//template<typename T1, typename T2>   //шаблонная функция
	//auto sum(T1 t1, T2 t2) {
	//	return t1 + t2;
	//}

	
	template<typename T>
	void Matrix<T>::Print()
	{
		for (int i = 0; i < width; ++i) {
			for (int j = 0; j < height; ++j) {
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}
	}



	int main() {

		srand(time(NULL));
		//// auto определяет свм тип переменной, но при этом сильно напрягает компилятор
		//auto x = 123;

		////объявить переменную "у" с таким же типом что и у "х"
		//decltype(x) y;

		Matrix <int> a(5, 6);
		a.Print();
		system("pause");
		return 0;
	}
