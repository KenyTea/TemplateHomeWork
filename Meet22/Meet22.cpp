// Meet22.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include <string>
using namespace std;


int main()
{
	string line = "123";
	int lineINT = stoi(line); // Функция stoi преобразует последовательность элементов string в значение типа int и возвращает это значение.
	cout << lineINT  << endl;

    return 0;
}

