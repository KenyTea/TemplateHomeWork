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

void shared_ptr() { // ��������� ���� ��� � ������� ����������� ������ "�"
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

void unique_ptr() { // �� ��� ����������, ���� const

	std::unique_ptr<int> x(new int(5));
}

int main() {
	
	foo();
	std::cout << std::endl;
	shared_ptr();
	std::cout << std::endl;
	std::shared_ptr<int> x(new int(5));
	use_count(x);
	system("pause");
	return 0;
}