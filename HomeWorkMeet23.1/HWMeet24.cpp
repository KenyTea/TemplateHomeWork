#include <iostream>
#include <string>
#include <fstream>
#include <streambuf>
using namespace std;

//*Задание 1
/*К уже существующему проекту класса Student добавьте меха-
низмы сохранения/загрузки данных класса. Используйте меха-
низм потоков для файловых операций.*/
class Human {
public:
	string Name;

	
	Human() {}
	~Human() {}
};

class Student : public Human {
public:
	int Course;
	string Specialty;
	Student() {}
	Student(string Name, int Course, string Specialty) {
		this->Name = Name;
		this->Course = Course;
		this->Specialty = Specialty;
	}
		
		~Student() {}
		
		void show() {
			cout << "Student name - " << Name << " | " 
				 << "Course - " <<  Course << " | "
				 << "Specialty - " << Specialty << endl;
			cout << endl;

		}

		void GetInFile() {
			ofstream fout; // создаём переменную типа ofstream для записи
			fout.open("Student.txt", ofstream::app); // открываем файл и дополнительно указываем ofstream::app для дозаписывания в конец (без затирания)
			if (!fout.is_open()) { // проверка на открытия файла
				cout << "The file not found" << endl;
			}
			else { // посылаем в fout данные
				fout  << "\nStudent name - " << Name << " | "
					<< "Course - " << Course << " | "
					<< "Specialty - " << Specialty << endl;
				cout << endl;
			}
			fout.close(); // закрытие файла !!!
		}

		void SetOutFile() {
			ifstream fin; // создаём переменную типа ifstream для считывания
			fin.open("Student.txt"); // открывает файл
			if (!fin.is_open()) { // проверка на наличие файла
				cout << "The file not found" << endl;
			}
			else {
				string temp; // создаём временную переменную того же типа
				while(!fin.eof()) { // запускаем цикл с условием выхода eof - end of file
					temp = ""; // обнуляем переменную для исключения повтора последней записи
					getline(fin, temp); // используем getline(от std) с вложенными параметрами
				cout << temp << endl; // выводми на консоли
				}

			}	
			fin.close(); // закрываем файд !!!
		}

};


int main() {
	//#1
	Student *student = new Student("Alfar Latypov", 2, "Applied Mathematics");
	//student->show();
	student->GetInFile();
	student->SetOutFile();
	delete student;

	
	return 0;
}










