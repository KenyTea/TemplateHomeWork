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

	delete a;
	delete b;
    return 0;
}

