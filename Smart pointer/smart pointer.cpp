#include <iostream>
#include <memory>
#include <fstream>
#include <set>
#include <string>

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

void shared_ptr() { // проверяет весь кол и считает колличество ссылок "х"
	std::shared_ptr<int> x(new int(5));
	std::cout << "point's count - " << x.use_count() << std::endl;
	std::shared_ptr<int> y = x;
	std::cout<< "shared_ptr - " << *y << " " << *x << std::endl;
	std::cout << "shared_ptr Address - " << y << " " << x << std::endl;
	std::cout << "point's count - " << x.use_count() << std::endl;

}

void use_count(std::shared_ptr <int> & x) {
	std::cout << "point's count <x> - " << x.use_count() << std::endl;

}

void unique_ptr() { // не даёт копировать, типо const

	std::unique_ptr<int> x(new int(5));
}

int main() {
	
	foo();
	std::cout << std::endl;
	shared_ptr();
	std::cout << std::endl;
	std::shared_ptr<int> x(new int(5));
	use_count(x);
	std::cout << std::endl;
	std::cout << std::endl;

	std::string n;
	std::getline(std::cin, n);
	std::set<char> b;
	for (size_t i = 0; i < n.length(); i++)
	{
		if (b.find(n[i]) != b.end()) {
			std::cout << "not unique" << std::endl;
			return 0;
		}
		else { b.insert(n[i]); }
	}
	std::cout << "unique" << std::endl;
	system("pause");
	return 0;
}