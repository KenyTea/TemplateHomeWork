#include <iostream>
#include <string>
#include <fstream>
#include <streambuf>
using namespace std;

//*������� 1
/*� ��� ������������� ������� ������ Student �������� ����-
����� ����������/�������� ������ ������. ����������� ����-
���� ������� ��� �������� ��������.*/
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


};

int main() {
	//#1
	Student *aspirant = new Student("Alfar", 2, "Applied Mathematics");
	aspirant->show();
	delete aspirant;

	
	return 0;
}










