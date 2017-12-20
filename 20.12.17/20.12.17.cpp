//итераторы iterators
#include <iostream>
#include <vector>


int main() {
	int arr[10] = { 1,2,3,4,5,6,7,8,9,0 };
	std::vector <int> x(arr, arr + 10);
	std::vector <int> ::iterator it = x.begin(); // iterator необходим для бега по массиву, чтоб не вышел из деапазона
	for (; it != x.end(); ++it)
	{
		std::cout << *it << '\t';
	}
	std::cout << std::endl;


	system("pause");
	return 0;
}