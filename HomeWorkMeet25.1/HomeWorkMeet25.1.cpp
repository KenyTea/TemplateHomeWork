
// HomeWork_16.12.17.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<string>

using namespace std;
/*Задание №1
Реализуйте программу, которая предоставляет функциональ -
ность по работе с файлами.Приложение получает у пользовате -
ля путь к файлу, после чего программа отображает интерфейс по
анализу содержимого файла.
Возможности интерфейса :
■ Поиск заданной строки(по итогам показывать статистику
	поиска строки по всему файлу);
■ Замена строки на новую строку(по итогам показать статисти -
	ку по замене строки);
■ Отображение файла на экран;
■ Переворот содержимого файла.
Используйте для работы с файлами потоки, а для работы со
строками класс string.*/

class String {
public:
	string str, temp, path, find, pos;
	String() {}
	~String() {}

	string CreateFile() {
		//string path;
		cout << " Please enter name file - ";
		getline(cin, path);
    	return path;
	}


	void GetInFile() {
		ofstream fout; // создаём переменную типа ofstream для записи
		fout.open(CreateFile(), ofstream::app); // открываем файл и дополнительно указываем ofstream::app для дозаписывания в конец (без затирания)
		if (!fout.is_open()) { // проверка на открытия файла
			cout << "The file not found" << endl;
		}
		else { // посылаем в fout данные
			fout << str << endl;
			cout << endl;
		}
		fout.close(); // закрытие файла !!!
	}

	void SetOutFile() {
		ifstream fin; // создаём переменную типа ifstream для считывания
		fin.open(CreateFile()); // открывает файл
		if (!fin.is_open()) { // проверка на наличие файла
			cout << "The file not found" << endl;
		}
		else {
			//string temp; // создаём временную переменную того же типа
			while (!fin.eof()) { // запускаем цикл с условием выхода eof - end of file
				temp = ""; // обнуляем переменную для исключения повтора последней записи
				getline(fin, temp); // используем getline(от std) с вложенными параметрами
				cout << temp << endl; // выводми на консоли
			}

		}
		fin.close(); // закрываем файд !!!
	}

	void Substitution() {
		ofstream fout;
		//string str;
		fout.open(CreateFile()); cin >> str;
    }

	void FindString() {
		ifstream fin(CreateFile());
		size_t npos;
		cout << "\n\t\twhat to look for? - "; cin >> find;
		pos = str.find(find);
		while (getline(fin, str)) { cout  << str << endl; }
		if (pos != string :: npos) { cout << "\n\t\tFound at pos = " << pos + 1 << "\n"; system("pause"); }
		else { cout << "\n\t\tNot found\n"; }
		
	}

	void Coup() {
		for (int i = str.size() - 1; i >= 0; --i)
			cout << str[i]; cout << "\n\n";
	}


};


void main()
{

	int choice;
	string str, find, fpath = menu();
	size_t pos;

	while (true) {
		system("cls");
		cout << "\n\t--------------<< M E N U >>--------------\n";
		cout << "\n\t[ 1 ] - Push 1 to display the file on the screen"; //¦ Отображение файла на экран
		cout << "\n\t[ 2 ] - Push 2 to enter data into the file";  //¦ Замена строки на новую строку 
		cout << "\n\t[ 3 ] - Push 3 to add into file";  //¦ Добписать строки в файл 
		cout << "\n\t[ 4 ] - Push 4 to find in the file";  //¦ Поиск заданной строки
		cout << "\n\t[ 5 ] - Push 5 to reverse the file";  //¦ Переворот содержимого файла
		cout << "\n\t[ 0 ] - Push 0 to EXIT";  //¦ EXIT



		cout << "\n\n\t     Your choice is - "; cin >> choice;

		ifstream fin(fpath);
		ofstream fout;

		switch (choice)
		{
		case 1:
			if (fin.is_open())
				while (getline(fin, str)) { system("cls"); cout << endl << endl << "\t\t" << str << endl << endl << endl << endl; } //¦ Отображение файла на экран
			else cout << "Ne otkruli";	 system("pause"); break;
		case 2: fout.open(fpath); cin >> str;//getline(cin, str);                     //¦ Замена строки на новую строку 
			if (fout.is_open()) { fout << str; }  break;
		case 3: fout.open(fpath, ios::app); cin >> str;                              //¦ Добписать строки в файл 
			if (fout.is_open()) { fout << str; }  break;
		case 4: system("cls");                                                      //¦ Поиск заданной строки
			cout << "\n\t\twhat to look for? - "; cin >> find;
			pos = str.find(find);
			while (getline(fin, str)) { system("cls"); cout << endl << endl << "\t\t" << str << endl; }
			if (pos != string::npos) { cout << "\n\t\tFound at pos = " << pos + 1 << "\n"; system("pause"); }
			else { std::cout << "\n\t\tNot found\n"; system("pause"); }
			break;
		case 5: system("cls"); cout << "\n\t\t";
			for (int i = str.size() - 1; i >= 0; --i)
				std::cout << str[i]; cout << "\n\n"; system("pause"); break;
		case 0: fin.close(); fout.close(); return;

		}
	}
}






