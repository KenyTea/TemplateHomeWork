// Meet22.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include <string>
using namespace std;

class MyException : public exception {
public:
	virtual const char * what() const {
		return "No division by zero is allowed";
	}

};

void divide(string a) {
	if (a.length() > 10) {
		throw MyException();
	}
	else cout << "OK" << endl;
}


int convert(string s) {
	int res = 0, radix = 1;
	for (int i = s.length() - 1; i >= 0; --i) {
		res += radix * ((int)s[i] - 48);
			radix *= 10;

	}
	return res;
}

int main()
{
	string line = "123";
	int lineINT = stoi(line); // Функция stoi преобразует последовательность элементов string в значение типа int и возвращает это значение.
	cout << lineINT  << endl;

	cout << convert(line) << endl;
	try { // если реализация не сработала, то catch (лови)
		divide("123");

	}
	catch (MyException e) {
		cout << e.what() << endl; // вывод ошибки
	}
    return 0;
}

