// TypeСonversion.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <typeinfo>


using namespace std;

class A {};
class B : public A {};

int main()
{
	A a;
	B b;
	cout << typeid(a).before(typeid(b)) << endl;
	cout << typeid(a).name()<< endl;



    return 0;
}

