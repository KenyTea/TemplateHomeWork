#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <string>
#include<algorithm> // for sort
#include <unordered_map>
#include <array>
#include <time.h>


class A { // functor
	public:
	bool operator() (int i, int j) { return i<j; }
};

int main() {
	A a;
	srand(time(NULL));
	std::vector<int> x (10);
	
	std::for_each(x.begin(), x.end(), [](int & a) {a = rand() % 10; std::cout << a << " "; }); std::cout << std::endl; // set random numbers in vector
	
	std::cout << "Min element " << *std::min_element(x.begin(), x.end(), a); std::cout << std::endl; // min element
	std::cout << "Max element " << *std::max_element(x.begin(), x.end(), a); std::cout << std::endl; // max lement

	
	system("pause");
	return 0;
}