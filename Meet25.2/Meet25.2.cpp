// Meet25.2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<string>

using namespace std;
/*Задание №2
Создайте приложение «Валидатор HTML-файлов». Приложе-
ние запрашивает у пользователя путь к файлу, после чего прове-
ряет файл на валидность. Критерием валидности для вашего про-
екта являются правила: все открытые теги должны закрываться,
если был знак < его должен закрыть знак >. По итогам валидации
Лабораторная работа №25 Лабораторная работа №<Номер дз>
нужно отобразить результат проверки на экран. Используйте для
работы с файлами потоки, а для работы со строками класс string.
Примеры:
Содержимое валидного файла
<html>
<body>To be or not to be</body>
</html>
Содержимое невалидного файла
<html>
<body To be or not to be</body>
</html>*/




void main() 
{
	string file;
	string str;
	int open = 0;
	int close = 0;
	cout << "Enter file name - ";
	getline(cin, file);
	

	ifstream fin(file); // открываем 
    if (fin.is_open()) {
		cout << endl;
		while (!fin.eof()) { getline(fin, str); cout << str << endl; } //пока не конец eof записываем в str и выводим
		cout << endl;
	}
	else cout << "The file is not open";
	


	for (int i = 0; i < str.length(); i++) { //подсчёт тэгов
		if (str[i] == '<')	open++;
		if (str[i] == '>')	close++;
	}
	if (fin.is_open()) {
		if (open == close) { // проверка на валидатность
			cout << endl;
			cout << "The file is validate" << endl;
			cout << "< -" << open << "  |  " << "> -" << close << endl;
		}
		else cout << "The file is not validate" << endl;
	}
	else {
		cout << endl;
		cout << "ERROR" << endl;
	}
	ofstream fout; //на этом этапе можно ввести корректировки в файл, добавить не достающий тег, даже заменить все содержимое
	fout.open(file, ios::app); cin >> str;
	if (fout.is_open()) { fout << str; }

	fin.close(); 
	fout.close();

}
















