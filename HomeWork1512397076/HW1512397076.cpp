#include <iostream>
#include <string>
using namespace std;

/*������� 1
�������� ����� Student, ������� ����� ��������� �������-
��� � ��������.
� ������� ��������� ������������, ���������� �����
Aspirant (�������� � �������, ������� ��������� � ������
������������ ������) ����������� �� Student.*/

class Student {
public:
	string Name;
	int Course;
	
	Student() {}
	~Student() {}
};

class Aspirant : public Student {
public:
	int YearOfStudy;
	string Specialty;
	Aspirant() {}
	Aspirant(string Name, int YearOfStudy, string Specialty) {
		this->Name = Name;
		this->Course = Course;
		this->YearOfStudy = YearOfStudy;
		this->Specialty = Specialty;
	}
		
		~Aspirant() {}
		
		void show() {
			cout << "Aspirant name - " << Name << " | " 
				 << "Year Of Study - " << YearOfStudy << " | "
				 << "Specialty - " << Specialty << endl;
			cout << endl;

		}
};

int main() {
	Aspirant *aspirant = new Aspirant("Alfar", 7, "Applied Mathematics");
	aspirant->show();
	delete aspirant;
	return 0;
}


/*������� �2
�������� ����� Passport (�������), ������� ����� ���������
���������� ���������� � ���������� �������.
� ������� ��������� ������������, ���������� �����
ForeignPassport (������.�������) ����������� �� Passport.
��������, ��� ����������� ������� �������� ������ ��-
�������� ������, ����� ������ � �����, ����� ������������ ��-
������.*/


/*������� �3
������� ����������� ������� ����� ������������� ��������
� ����������� ������ ������������, ����������, ��������.
���������� ����� � ��������� ��������� ���������� � ������
������ ������������ ���������.*/


