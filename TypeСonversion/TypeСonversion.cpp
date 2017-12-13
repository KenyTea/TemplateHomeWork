// TypeСonversion.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <typeinfo>
using namespace std;

class A {
public:
	A() {}
	virtual~A() {}
};
class B : public A {};




int main()
{
	/*A a;
	B b;
	cout << typeid(a).before(typeid(b)) << endl;
	cout << typeid(a).name()<< endl;*/

	A*a = new B();
	B *b = dynamic_cast<B *>( new A()); // базовый класс заставили взять тип дочернего с помощю <dynamic_cast> БЕСПОЛЕЗНАЯ ФИГНЯ

	int y = 5;
	double x = static_cast <double>(y); // перевод int в  double

	double q = 5.5;
	int w = static_cast <int>(q); // перевод double в int 

	const double t = 4.0;
	double *r = const_cast<double *>(&t); // обход const с  помощю <const_cast>
	const_cast<double &>(t) = 5;

	B *c = reinterpret_cast<B *>(&a); // приводим тип без проверки НЕ ИСПОЛЬЗОВАТЬ !!!!


	cout << "t = " <<  t << endl;
	cout << "*r = " << *r << endl;
	cout << x << endl;
	cout << w << endl;

	delete a;
	delete b;
    return 0;
}

