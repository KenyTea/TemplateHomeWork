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

		void GetInFile() {
			ofstream fout; // ������ ���������� ���� ofstream ��� ������
			fout.open("Student.txt", ofstream::app); // ��������� ���� � ������������� ��������� ofstream::app ��� ������������� � ����� (��� ���������)
			if (!fout.is_open()) { // �������� �� �������� �����
				cout << "The file not found" << endl;
			}
			else { // �������� � fout ������
				fout  << "\nStudent name - " << Name << " | "
					<< "Course - " << Course << " | "
					<< "Specialty - " << Specialty << endl;
				cout << endl;
			}
			fout.close(); // �������� ����� !!!
		}

		void SetOutFile() {
			ifstream fin; // ������ ���������� ���� ifstream ��� ����������
			fin.open("Student.txt"); // ��������� ����
			if (!fin.is_open()) { // �������� �� ������� �����
				cout << "The file not found" << endl;
			}
			else {
				string temp; // ������ ��������� ���������� ���� �� ����
				while(!fin.eof()) { // ��������� ���� � �������� ������ eof - end of file
					temp = ""; // �������� ���������� ��� ���������� ������� ��������� ������
					getline(fin, temp); // ���������� getline(�� std) � ���������� �����������
				cout << temp << endl; // ������� �� �������
				}

			}	
			fin.close(); // ��������� ���� !!!
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










