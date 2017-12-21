#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <string>
#include<algorithm> // for sort
#include <unordered_map>

// lymbda
class A {
public:
	A() {
		std::cout << "A()" << std::endl;
	}
	A(int x): value(x){}
	~A() {
		std::cout << "~A()" << std::endl;
	}
	int value;
	friend std::ostream & operator << (std::ostream &, const A &);
	friend void operator >> (std::istream & stream, const A & a);

	void Show() {

		std::cout << value << std::endl;
	}

};
std::ostream & operator << (std::ostream & stream, const A & a) {
	return stream << a.value;
}
void operator >> (std::istream & stream, const A & a) {
	stream >> a;
} 



int main() {

	std::vector<A> x = { A(1), A(2) ,A(3) };
	x.push_back(A(6));
	x.shrink_to_fit();
	x.pop_back();
	x.pop_back();
	std::cout << x.size() << std::endl;
	std::cout << x.max_size() << std::endl;
	int y;
	std::cin >> y;
	
	auto a = std::find_if(x.begin(), x.end(), [y](A & a) {return a.value == y; }); // Lambda - [y](A & a) {return a.value == y; }
	std::cout << std::endl;

	if (a != x.end()) {
		std::cout << *a << '\n';
	}
	else std::cout << "not found" << std::endl;

	system("pause");
	return 0;
}