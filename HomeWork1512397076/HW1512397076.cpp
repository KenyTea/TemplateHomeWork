#include <iostream>
#include <string>
using namespace std;

/*Задание 1
Создайте класс Student, который будет содержать информа-
цию о студенте.
С помощью механизма наследования, реализуйте класс
Aspirant (аспирант – студент, который готовится к защите
кандидатской работы) производный от Student.*/

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


/*Задание №2
Создайте класс Passport (паспорт), который будет содержать
паспортную информацию о гражданине Украины.
С помощью механизма наследования, реализуйте класс
ForeignPassport (загран.паспорт) производный от Passport.
Напомним, что заграничный паспорт содержит помимо па-
спортных данных, также данные о визах, номер заграничного па-
спорта.*/


/*Задание №3
Создать абстрактный базовый класс «Транспортное средство»
и производные классы «Автомобиль», «Велосипед», «Повозка».
Подсчитать время и стоимость перевозки пассажиров и грузов
каждым транспортным средством.*/


