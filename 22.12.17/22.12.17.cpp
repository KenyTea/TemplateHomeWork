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


class A { // functor
	public:
	bool operator() (int i, int j) { return i<j; }
};

int main() {
	A a;
	srand(time(NULL));
	std::vector<int> x (10);
	
	std::for_each(x.begin(), x.end(), [](int & a) {a = rand() % 10; std::cout << a << " "; }); std::cout << std::endl; // set random numbers in vector
	
	std::cout << "Min element " << *std::min_element(x.begin(), x.end()/*, a*/); std::cout << std::endl; // min element whithout functor
	std::cout << "Max element " << *std::max_element(x.begin(), x.end(), a); std::cout << std::endl; // max lement
	std::cout << "Greater " << *std::max_element(x.begin(), x.end(), std::greater<int>()); // sort 0 - 9
	std::cout << "Less " << *std::max_element(x.begin(), x.end(), std::less<int>());// sort 9 - 0
	system("pause");
	return 0;
}