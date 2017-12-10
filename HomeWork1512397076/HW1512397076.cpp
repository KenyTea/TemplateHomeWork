#include <iostream>
#include <string>
using namespace std;

///*Задание 1
//Создайте класс Student, который будет содержать информа-
//цию о студенте.
//С помощью механизма наследования, реализуйте класс
//Aspirant (аспирант – студент, который готовится к защите
//кандидатской работы) производный от Student.*/
//
//class Student {
//public:
//	string Name;
//	int Course;
//	
//	Student() {}
//	~Student() {}
//};
//
//class Aspirant : public Student {
//public:
//	int YearOfStudy;
//	string Specialty;
//	Aspirant() {}
//	Aspirant(string Name, int YearOfStudy, string Specialty) {
//		this->Name = Name;
//		this->Course = Course;
//		this->YearOfStudy = YearOfStudy;
//		this->Specialty = Specialty;
//	}
//		
//		~Aspirant() {}
//		
//		void show() {
//			cout << "Aspirant name - " << Name << " | " 
//				 << "Year Of Study - " << YearOfStudy << " | "
//				 << "Specialty - " << Specialty << endl;
//			cout << endl;
//
//		}
//};

///*Задание №2
//Создайте класс Passport (паспорт), который будет содержать
//паспортную информацию о гражданине Украины.
//С помощью механизма наследования, реализуйте класс
//ForeignPassport (загран.паспорт) производный от Passport.
//Напомним, что заграничный паспорт содержит помимо па-
//спортных данных, также данные о визах, номер заграничного па-
//спорта.*/
//
//class Passport {
//	
//	string Name;
//	string Birthday;
//	string Address;
//public:
//	void SetName(string &Name) {
//		this->Name = Name;
//	}
//	void SetBirthday(string &Birthday) {
//		this->Birthday = Birthday;
//	}
//	void SetAddress(string &Address) {
//		this->Address = Address;
//	}
//	string  GetName()  {
//		return Name;
//	}
//	string  GetBirthday() {
//		return Birthday;
//	}
//	string  GetAddress() {
//		return Address;
//	}
//
//	Passport() {}
//
//	Passport(string Name1, string Birthday1, string  Address1) {
//		SetName(Name1), SetBirthday(Birthday1), SetAddress(Address1);
//	}
//	
//	~Passport() {}
//
//	void ShowPassport() {
//		cout << "Passport information" << endl;
//		cout << "Name - " << GetName() << endl;
//		cout << "Birthday - " << GetBirthday() << endl;
//		cout << "Address - " << GetAddress() << endl;
//		cout << endl;
//	}
//
//};
//
//class ForeignPassport : public Passport {
//	int Num;
//	string Country;
//	string Become;
//	string Visa;
//public:
//	void SetNum(int Num) {
//		this->Num = Num;
//	}
//
//	void SetCountry(string  &Country) {
//		this->Country = Country;
//	}
//
//	void SetBecome(string &Become) {
//		this->Become = Become;
//	}
//
//	void SetVisa(string &Visa) {
//		this->Visa = Visa;
//	}
//
//	int const GetNum() {
//		return Num;
//	}
//
//	string GetCountry() {
//		return Country;
//	}
//
//	string GetBecome() {
//		return Become;
//	}
//
//	string GetVisa() {
//		return Visa;
//	}
//
//	ForeignPassport() {}
//
//	ForeignPassport(int Num1, string Country1, string Become1, string Visa1) {
//		SetNum(Num1), SetCountry(Country1), SetBecome(Become1), SetVisa(Visa1);
//	}
//
//	~ForeignPassport() {}
//
//	void ShowForeignPassport() {
//		cout << "Foreign Passport information" << endl;
//		cout << "ID - " << GetNum() << endl;
//		cout << "Country - " << GetCountry() << endl;
//		cout << "Become - " << GetBecome() << endl;
//		cout << "Visa - " << GetVisa() << endl;
//		cout << endl;
//
//	}
//
//};

/*Задание №3
Создать абстрактный базовый класс «Транспортное средство»
и производные классы «Автомобиль», «Велосипед», «Повозка».
Подсчитать время и стоимость перевозки пассажиров и грузов
каждым транспортным средством.*/

class Vehicle {
protected:
	double *time;
	double *price;
	double *distance;
	virtual void TimePriceTransport(double distance) = 0;
	Vehicle() {}
	~Vehicle() {}
};

class Car: public Vehicle {
	const double carspeed = 60;
public:
	Car() {
				time = new double;
				price = new double;
				distance = new double;
			}
	virtual void TimePriceTransport(double distance) {
		*time = distance / carspeed;
		*price = distance / 50;
		cout << "Car's speed - " << carspeed << " km/h" << endl;
		cout << "Travel time - " << *time << " h." << endl;
		cout << "Price - " << *price << " $" << endl;
		cout << endl;
	}

	~Car() {
		delete time;
		delete price;
		delete distance;
	}

};

class Bike : public Vehicle {
	const double bikespeed = 20;
public:

	Bike() {
		distance = new double;
		price = new double;
		time = new double;
	}
	void TimePriceTransport(double distance) {
		*time = distance / bikespeed;
		*price = distance / 20;
		cout << "bike's speed - " << bikespeed << " km/h" << endl;
		cout << "Travel time - " << *time << " h." << endl;
		cout << "Price - " << *price << " $" << endl;
		cout << endl;
	}
	~Bike() {
		delete price;
		delete time;
		delete distance;
	};
};

class Wagon : public Vehicle {
	const double wagonspeed = 40;
public:
	Wagon() {
		distance = new double;
		price = new double;
		time = new double;
	}
	 void TimePriceTransport(double distance) {
		*time = distance / wagonspeed;
		*price = distance / 5;
		cout << "Wagon's speed - " << wagonspeed << " km/h" << endl;
		cout << "Travel time - " << *time << " h." << endl;
		cout << "Price - " << *price << " $" << endl;
		cout << endl;
	}
	~Wagon() {
		delete price;
		delete time;
		delete distance;
	}
};
	

int main() {
	//#1
	/*Aspirant *aspirant = new Aspirant("Alfar", 7, "Applied Mathematics");
	aspirant->show();
	delete aspirant;*/

	//#2
	/*Passport *passport = new Passport("Ivanov Ivan Ivanovich", "12.07.1983", "Almaty, Kalinina 151, ap. 25");
	passport->ShowPassport();


	ForeignPassport * Fpassport = new ForeignPassport(12345, "Kazakhstan","male", "New Zealand");
	Fpassport->ShowForeignPassport();

	delete passport;
	delete Fpassport;*/

	//#3
	Car * car = new Car();
	car->TimePriceTransport(10);

	Bike * bike = new Bike();
	bike->TimePriceTransport(10);

	Wagon * wagon = new Wagon();
	wagon->TimePriceTransport(10);

	delete bike;
	delete car;
	delete wagon;
	return 0;
}








