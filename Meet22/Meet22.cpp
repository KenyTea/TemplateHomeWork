// Meet22.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include <string>
using namespace std;

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

    return 0;
}

