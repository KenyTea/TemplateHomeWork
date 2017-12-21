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
};
std::ostream & operator << (std::ostream & stream, const A & a) {
	return stream << a.value;
}
void operator >> (std::istream & stream, const A & a) {
	stream >> a;
}


int main() {

	std::vector<A> x = { A(1), A(2) ,A(3) };

	return 0;
}