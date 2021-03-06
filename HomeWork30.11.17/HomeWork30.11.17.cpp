#include"stdafx.h"
#include <iostream>

using namespace std;

/*Создать шаблонный класс-контейнер Array, который пред- ставляет собой массив,
позволяющий хранить объекты заданного типа. Класс должен реализовывать следующие
функции:
■ GetSize – получение размера массива (количество элементов, под которые выделена
память);
■ SetSize(int size, int grow = 1) – установка размера массива (если параметр size больше
предыдущего размера массива, то выделяется дополнительный блок памяти, если нет, то
«лишние» элементы теряются и память освобождается); параметр grow определяет для
какого количества элементов необходи- мо выделить память, если количество элементов
превосходит текущий размер массива. Например, SetSize(5, 5); означает, что при
добавлении 6-го элемента размер массива становится равным 10, при добавлении 11-го -
15 и т. д.;
■ GetUpperBound - получение последнего допустимого индекса в массиве. Например,
если при размере массива 10, вы добавляете в него 4 элемента, то функция вернет 3;
■ IsEmpty - массив пуст?; Лабораторная работа №12 Лабораторная работа №<Номер дз>
■ FreeExtra - удалить «лишнюю» память (выше последнего до- пустимого индекса);
■ RemoveAll – удалить все;
■ GetAt -получение определенного элемента (по индексу);
■ SetAt – установка нового
значения для определенного элемен- та (индекс элемента должен быть меньше текущего
размера массива);
■ operator [] – для реализации двух предыдущих функций;
■ Add – добавление элемента в массив (при необходимости массив увеличивается на
значение grow функции SetSize);
■ Append – «сложение» двух массивов;
■ operator =;
■ GetData – получения адреса массива с данными;
■ InsertAt – вставка элемента(-ов) в заданную позицию;
■ RemoveAt – удаление элемента(-ов) с заданной позиции.*/

template <class T>
class Array {
public:
	T * Arr;
	int size = 5;
	int count = 0;

	Array() {
		Arr = new T[size];
	}
	~Array() {
		delete Arr;
	}

	int GetSize() {
		return size;
	}

	void SetSize(int size, int grow = 1);

	int GetUpperBound() {
		return count - 1;
	}

	void IsEmpty() {
		if (size < 1) { cout << "Array is empty"; }
	}

	void FreeExtra();

	void RemoveAll();

	T GetAt(int index) {
		return Arr[index];
	}

	void SetAt(T t, int index);

	void Add(T t) {
		SetSize(size, 5);
		Arr[count] = t;
		count++;
	}

	void InsertAt(T t, int index);

	void GetData() {
		cout << &Arr << endl;
	}

	void RemoveAt(int index);


	void show();

};


int main() {

	Array<char> a;
	Array<char> b;
	a.SetSize(5, 5);
	b.SetSize(5, 5);
	a.Add('a');
	a.Add('b');
	a.Add('c');
	a.Add('d');
	a.Add('e');

	b.Add('q');
	b.Add('p');
	b.Add('x');
	b.Add('y');
	b.Add('z');
	cout << a.GetAt(3) << endl;

	a.InsertAt('A', 3);
	a.SetAt('L', 1);


	a.show();
	b.show();
	system("pause");
	return 0;
}

template<class T>
void Array<T>::SetSize(int size, int grow)
{
	if (size < size + grow) {   // условие
		size = size + grow;  // увеличиваем размер 
		T * NewArr = new T[size]; // создаём  новый массив
		for (int i = 0; i < size; ++i) // заполняем, перекидывая сос старого
			NewArr[i] = Arr[i];
		delete Arr; // удаляем старый массив
		Arr = NewArr; // приравниваем новый к старому
		this->size = size; // отправляем размер из метода.
	}
}

template<class T>
void Array<T>::FreeExtra() {
	size = count;
	T* NewArr = new T[size];
	for (int i = 0; i < size; i++)
		NewArr[i] = arr[i];
	delete arr;
	arr = NewArr;
}

template<class T>
void Array<T>::RemoveAll()
{
	delete Arr;
	count = 0;
	size = 1;
	T * Arr = new T[size];
}

template<class T>
void Array<T>::SetAt(T t, int index)
{
	if (index < size) {
		Arr[index] = t;
	}
}

template<class T>
void Array<T>::InsertAt(T t, int index)
{
	if (index < size) {
		int temp = 0;
		SetSize(size, 5);
		size = size + 1;
		T * NewArr = new T[size];
		for (int i = 0; i < index; i++)
			NewArr[temp++] = Arr[i];

		NewArr[index] = t;
		temp++;
		for (int i = index; i <= count; i++)
			NewArr[temp++] = Arr[i];

		delete Arr;
		Arr = NewArr;
		count++;

	}
}

template<class T>
void Array<T>::RemoveAt(int index)
{
	if (index < size)
	{
		int temp = 0;
		T * NewArr = new T[size];
		for (int i = 0; i < index; i++)
			NewArr[temp++] = Arr[i];
		for (int i = index + 1; i < size; i++)
			NewArr[temp++] = Arr[i];

		delete Arr;
		Arr = NewArr;
		this->size = size - 1;
		count--;


	}
}

template<class T>
void Array<T>::show()
{
	cout << endl;
	for (int i = 0; i < count; i++)
		cout << Arr[i] << " ";
	cout << endl;
}



