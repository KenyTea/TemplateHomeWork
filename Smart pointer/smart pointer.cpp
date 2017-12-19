#include <iostream>
#include <memory>
#include <fstream>

class A {
public:
	A() {
		std::cout << "A()" << std::endl;
	}
	~A() {
		std::cout << "~A()" << std::endl;
	}
	int value;
	friend std::ostream & operator << (std::ostream &, const A &);
	
};

std::ostream & operator << (std::ostream & stream, const A & a)
{
	stream << a.value;
	return stream;
}

void foo() {
	std::auto_ptr<A> a(new A());
	a->value = 5;
	std::auto_ptr<A> b = a;
	std::cout << b->value << std::endl;

}

int main() {
	
	foo();
	system("pause");
	return 0;
}