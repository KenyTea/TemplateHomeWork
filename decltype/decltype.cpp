
#include "stdafx.h"

using namespace std;


template<typename T>
class Matrix {

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
				arr[j][k] = rand() % 20;

	}



	~Matrix() {
		for (int = 0; i < width; i++) {
			delete	arr[i];
		}
		delete arr;
	}
	};


	template<typename T1, typename T2>   //шаблонная функция
	auto sum(T1 t1, T2 t2) {
		return t1 + t2;
	}

	template<typename T>

	int main() {
		// auto определяет свм тип переменной, но при этом сильно напрягает компилятор
		auto x = 123;

		//объявить переменную "у" с таким же типом что и у "х"
		decltype(x) y;

		system("pause");
		return 0;
	}