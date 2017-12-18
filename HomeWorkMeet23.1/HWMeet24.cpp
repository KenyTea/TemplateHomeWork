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

			ofstream fout;
			fout.open("Student.txt", ofstream::app);
			if (!fout.is_open()) {
				cout << "The file not found" << endl;
			}
			else {
				fout  << "\nStudent name - " << Name << " | "
					<< "Course - " << Course << " | "
					<< "Specialty - " << Specialty << endl;
				cout << endl;
			}
			fout.close();
		}

		void SetOutFile() {
			ifstream fin;
			fin.open("Student.txt");
			if (!fin.is_open()) {
				cout << "The file not found" << endl;
			}
			//else {
			//	fin >> ;
			//}
		
		
		}

};


int main() {
	//#1
	Student *student = new Student("Alfar", 2, "Applied Mathematics");
	student->show();
	student->GetInFile();
	delete student;

	
	return 0;
}










