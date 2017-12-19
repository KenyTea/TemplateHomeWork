//#include "stdafx.h"
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
	string str, path, find, pos;
	String() {}
	~String() {}

	string CreateFile() {
		getline(cin, path);
		return path;
	}


	void GetInFile() {
		ofstream fout; // создаём переменную типа ofstream для записи
		fout.open(path, ofstream::app); // открываем файл и дополнительно указываем ofstream::app для дозаписывания в конец (без затирания)
		if (!fout.is_open()) { // проверка на открытия файла
			cout << "The file not found" << endl;
		}
		else { // посылаем в fout данные
			cin >> str;
			fout << str << endl;
			cout << endl;
		}
		fout.close(); // закрытие файла !!!
		system("pause");
	}

	void Show() {
		ifstream fin; // создаём переменную типа ifstream для считывания
		fin.open(path); // открывает файл
		if (!fin.is_open()) { // проверка на наличие файла
			cout << "The file not found" << endl;
		}
		else {
			if (fin.is_open())
				while (getline(fin, str)) { system("cls"); cout << str << endl; }
			//string temp; // создаём временную переменную того же типа
			//while (!fin.eof()) { // запускаем цикл с условием выхода eof - end of file
			//	temp = ""; // обнуляем переменную для исключения повтора последней записи
			//	getline(fin, temp); // используем getline(от std) с вложенными параметрами
			//	cout << temp << endl; // выводми на консоли
			//}

		}
		fin.close(); // закрываем файд !!!
	}

	void Substitution() {
		ofstream fout;
		//string str;
		fout.open(path); cin >> str;
		fout.close();
	}

	void FindString() {
		ifstream fin(path);
		size_t npos;
		cout << "\n\t\tWhat to look for? - "; cin >> find;
		//pos = str.find(find);
		while (getline(fin, str)) { cout << str << endl; }
		/*if (find = str) { cout << "\n\t\tFound at pos = " << pos + 1 << "\n"; }
		else { cout << "\n\t\tNot found\n"; }*/

	}

	void Coup() {
		for (int i = str.size() - 1; i >= 0; --i)
			cout << str[i]; cout << "\n\n";
	}

	void Menu() {
		int choice;
		while (true) {
			system("cls");
			cout << "--------------M E N U--------------" << endl;
			cout << "Enter 1 to display the file on the screen" << endl;  // Отображение файла на экран
			cout << "Enter 2 to enter data into the file" << endl;  // Замена строки на новую строку 
			cout << "Enter 3 to add into file" << endl;  // Добписать строки в файл 
			cout << "Enter 4 to find in the file" << endl;  // Поиск заданной строки
			cout << "Enter 5 to reverse the file" << endl;  // Переворот содержимого файла
			cout << "Enter 0 to EXIT" << endl;
			cout << endl;
			cout << "Your choice is -  "; cin >> choice;
			switch (choice) {
			case 1: system("cls"); Show(); break;
			case 2: system("cls"); Substitution(); break;
			case 3: system("cls"); GetInFile(); break;
			case 4: system("cls"); FindString(); break;
			case 5: system("cls"); Coup(); break;
			case 0: return;
			}


		}



	}

};


int main()
{
	String S;
	cout << " Please enter name file - ";
	S.CreateFile();
	S.Menu();
	system("pause");
	return 0;
}