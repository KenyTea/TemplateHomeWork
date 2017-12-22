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
	std::cout << std::endl;

	std::cout << "Min element " << *std::min_element(x.begin(), x.end()/*, a*/); std::cout << std::endl; // min element whithout functor
	std::cout << "Max element " << *std::max_element(x.begin(), x.end(), a); std::cout << std::endl; // max lement
	std::cout << std::endl;

	std::sort(x.begin(), x.end(), std::greater<int>()); // sort 0 - 9
	std::cout << "Greater "; std::for_each(x.begin(), x.end(), [](int & a) {std::cout  << a << " "; });
	std::cout << std::endl; 

	std::sort(x.begin(), x.end(), std::less<int>()); // sort 9 - 0
	std::cout << "Less "; std::for_each(x.begin(), x.end(), [](int & a) {std::cout << a << " "; });
	std::cout << std::endl;
	std::cout << std::endl;
	
	int n = 10;
	std::for_each(x.begin(), x.end(), [n](int & a) { a += n; }); // +10
	std::cout << "+10   "; std::for_each(x.begin(), x.end(), [n](int & a) {std::cout << a << " "; });
	std::cout << std::endl;

	std::for_each(x.begin(), x.end(), [n](int & a) { a -= n; });// -10
	std::cout << "-10   "; std::for_each(x.begin(), x.end(), [n](int & a) {std::cout << a << " "; });
	std::cout << std::endl;

	/*auto it = x.begin();
	while (it != x.end()) {
		auto y = std::find(it, x.end(), 1);
		if (y != x.end()) {
			x.erase(y);
		}
	}*/
	std::cout << std::endl;
	x.erase(std::remove(x.begin(), x.end(), 9), x.end());// remove 9 from vector
	std::cout << "Remove 9   "; std::for_each(x.begin(), x.end(), [n](int & a) {std::cout << a << " "; });

	int z = 2;
	x.erase(x.begin() + z);



	system("pause");
	return 0;
}