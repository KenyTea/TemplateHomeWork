// iterators
#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <string>
#include<algorithm> // for sort

void Vector() {
	int arr[10] = { 2,3,5,6,7,8,9,0,4,1 };
	std::vector <int> x(arr, arr + 10);
	std::vector <int> ::iterator it = x.begin(); // iterator It is necessary for running on an array, that did not leave the range
	for (; it != x.end(); ++it)
	{
		std::cout << *it << '\t';
	}
	std::cout << std::endl;

}
void Map() {
	std::map <std::string, int> dictionary;
	dictionary.emplace(std::make_pair<std::string, int>("123", 1));
	std::cout << dictionary.at("123") << std::endl;
	auto it2 = dictionary.begin();
	for (; it2 != dictionary.end(); ++it2) {
		std::cout << it2->first << '\t' << it2->second << '\t';
	}
	std::cout << std::endl;
}
void List() {
	int arr[10] = { 2,3,5,6,7,8,9,0,4,1 };
	std::list <int> y(arr, arr + 10);
	y.sort();                   //sort
	auto it1 = y.begin();
	for (; it1 != y.end(); ++it1)
	{
		std::cout << *it1 << '\t';
	}
	std::cout << std::endl;
}
void Multymap() {
	std::multimap <std::string, int> dictionary1;
	dictionary1.insert(std::make_pair<std::string, int>("123", 1));
	std::cout << dictionary1.find("123")->first << std::endl;
	dictionary1.insert(std::make_pair<std::string, int>("123", 5));
	auto it3 = dictionary1.begin();
	for (; it3 != dictionary1.end(); ++it3) {
		std::cout << it3->first << '\t' << it3->second << '\t';
	}
	std::cout << std::endl;
}
int main() {
	
	Vector();
	std::cout << "Vector" << std::endl;
	Map();
	std::cout << "Map" <<std::endl;
	List();
	std::cout << "List" << std::endl;
	Multymap();
	std::cout << "Multymap" << std::endl;


	system("pause");
	return 0;
}