// TrayCatch.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class MyException : public exception {
public:
	virtual const char * what() const {
		return "No division by zero is allowed";
}

};

float divide(float a, float b) {
	if (b == 0) {
		throw MyException();
	}
	else
		return a / b;
}

int main()
{
	try { // если реализация не сработала, то catch (лови)
		divide(2, 0);

	}
	catch (MyException e) {
		cout << e.what() << endl; // вывод ошибки
	}
    return 0;
}

