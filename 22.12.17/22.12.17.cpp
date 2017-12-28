#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <string>
#include<algorithm> // for sort
#include <unordered_map>
#include <array>
#include <time.h>
#include <functional>
/*Встреча №27
В контейнере типа vector хранится набор целых чисел. Создай-
те функторы для решения следующих задач:
■ Поиск минимального значения;
■ Поиск максимального значения;
■ Сортировка данных по убыванию;
■ Сортировка данных по возрастанию;
■ Увеличение значений в контейнере на заданную константу;
■ Уменьшение значений в контейнере на заданную константу;
■ Удаление элементов из контейнера равных искомому значе-
нию.
Не забывайте использовать алгоритмы там, где это необходимо.
*/

// Задача 1

//class A { // functor
//	public:
//	bool operator() (int i, int j) { return i<j; }
//};
//
//int main() {
//	A a;
//	srand(time(NULL));
//	std::vector<int> x (10);
//	
//	std::for_each(x.begin(), x.end(), [](int & a) {a = rand() % 10; std::cout << a << " "; }); std::cout << std::endl; // set random numbers in vector
//	std::cout << std::endl;
//
//	std::cout << "Min element " << *std::min_element(x.begin(), x.end()/*, a*/); std::cout << std::endl; // min element whithout functor
//	std::cout << "Max element " << *std::max_element(x.begin(), x.end(), a); std::cout << std::endl; // max lement
//	std::cout << std::endl;
//
//	std::sort(x.begin(), x.end(), std::greater<int>()); // sort 0 - 9
//	std::cout << "Greater "; std::for_each(x.begin(), x.end(), [](int & a) {std::cout  << a << " "; });
//	std::cout << std::endl; 
//
//	std::sort(x.begin(), x.end(), std::less<int>()); // sort 9 - 0
//	std::cout << "Less "; std::for_each(x.begin(), x.end(), [](int & a) {std::cout << a << " "; });
//	std::cout << std::endl;
//	std::cout << std::endl;
//	
//	int n = 10;
//	std::for_each(x.begin(), x.end(), [n](int & a) { a += n; }); // +10
//	std::cout << "+10   "; std::for_each(x.begin(), x.end(), [n](int & a) {std::cout << a << " "; });
//	std::cout << std::endl;
//
//	std::for_each(x.begin(), x.end(), [n](int & a) { a -= n; });// -10
//	std::cout << "-10   "; std::for_each(x.begin(), x.end(), [n](int & a) {std::cout << a << " "; });
//	std::cout << std::endl;
//
//	/*auto it = x.begin();
//	while (it != x.end()) {
//		auto y = std::find(it, x.end(), 1);
//		if (y != x.end()) {
//			x.erase(y);
//		}
//	}*/
//	std::cout << std::endl;
//	x.erase(std::remove(x.begin(), x.end(), 9), x.end());// remove 9 from vector
//	std::cout << "Remove 9   "; std::for_each(x.begin(), x.end(), [n](int & a) {std::cout << a << " "; });
//
//	int z = 2;
//	x.erase(x.begin() + z);
//
//
//
//	system("pause");
//	return 0;
//}


/*Измените функторы из первого задания в шаблонные клас-
сы-функторов. Проверьте работу полученного решения на раз-
ных контейнерах с разным содержимым.*/

// Задача 2
template <class T>
class A {
public:
		bool operator() (T i, T j) { return i<j; }
};

template <class T>
class plus {
public:
	T p;
	plus(T p) 
	{
		this->p = p;
	}
	bool operator() (T & t) 
	{
		return p += t; 
	}
};

template <class T>
class minus {
public:
	T m;
	minus(T m)
	{
		this->m = m;
	}
	bool operator() (T & t) {
		return m -= t;
	}
};

int main() {

	A <int> a;
	plus <int> b(10);
	minus <int> c(10);

	srand(time(NULL));
	std::vector<int> x (10);

	std::for_each(x.begin(), x.end(), [](int & a) {a = rand() % 10; std::cout << a << " "; }); std::cout << std::endl; // set random numbers in vector
	std::cout << std::endl;

	std::cout << "Min element " << *std::min_element(x.begin(), x.end(), a); std::cout << std::endl; // min element 
	std::cout << "Max element " << *std::max_element(x.begin(), x.end(), a); std::cout << std::endl; // max lement
	std::cout << std::endl;

	std::sort(x.begin(), x.end(), std::greater<int>()); // sort 0 - 9
	std::cout << "Greater "; std::for_each(x.begin(), x.end(), [](int & a) {std::cout  << a << " "; });
	std::cout << std::endl; 

	std::sort(x.begin(), x.end(), std::less<int>()); // sort 9 - 0
	std::cout << "Less "; std::for_each(x.begin(), x.end(), [](int & a) {std::cout << a << " "; });
	std::cout << std::endl;
	std::cout << std::endl;

	std::for_each(x.begin(), x.end(), b); // +10
	std::cout << "+10   "; std::for_each(x.begin(), x.end(), [](int & a) {std::cout << a << " "; });
	std::cout << std::endl;

	std::for_each(x.begin(), x.end(), c);// -10
	std::cout << "-10   "; std::for_each(x.begin(), x.end(), [](int & a) {std::cout << a << " "; });
	std::cout << std::endl;

	std::cout << std::endl;
	x.erase(std::remove(x.begin(), x.end(), 9), x.end());// remove 9 from vector
	std::cout << "Remove 9   "; std::for_each(x.begin(), x.end(), [n](int & a) {std::cout << a << " "; });
	
	int z = 2;
	x.erase(x.begin() + z);
	

	system("pause");
	return 0;
}