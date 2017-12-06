////#include "stdafx.h"
//
//#include <iostream>
//#include <string>
//using namespace std;
///*Задание №2
//Создать базовый класс «Домашнее животное» и производные
//классы «Собака», «Кошка», «Попугай», «Хомяк». С помощью кон-
//структора установить имя каждого животного и его характери-
//стики.
//Реализуйте для каждого из классов функции:
//Sound – издает звук животного (пишем текстом в консоль);
//Show – отображает имя животного;
//Type – отображает название его подвида.*/
//
//class Pets {
//public:
//	string Name;
//	virtual void Sound() {
//	}
//
//	virtual void Show() {
//	}
//
//	virtual void Type() {
//	}
//	Pets(){}
//	virtual ~Pets(){}
//};
//
//class Dog : public Pets {
//public:
//	void Sound() {
//		cout << "Gav Gav" << endl;
//	}	
//    void Show() {		
//		cout << Name << endl;
//	}
//	void Type() {
//		cout << "Bishon" << endl;
//	}	
//	~Dog() {}
//};
//
//class Cat : public Pets {
//public:
//	void Sound() {
//		cout << "Myu" << endl;
//	}
//	void Show() {	
//		cout << Name << endl;
//	}
//	void Type() {
//		cout << "Garden type" << endl;
//	}
//};
//
//class Parrot : public Pets {
//	void Sound() {
//		cout << "speaking" << endl;
//	}
//
//	void Show() {
//		cout << Name << endl;
//	}
//	void Type() {
//		cout << "Kakadu" << endl;
//	}
//};
//
//class Hamster : public Pets {
//	void Sound() {
//		cout << "Fr Fr Fr" << endl;
//	}
//	void Show() {
//		cout << Name << endl;
//	}
//	void Type() {
//		cout << "detachment of rodents" << endl;
//	}
//};
//
//
//int main() {
//	Pets * dog = new Dog();
//	dog->Name = "Felisity";
//	dog->Show();
//	dog->Sound();
//	dog->Type();
//	cout << "===============================" << endl;
//	Pets * cat = new Cat();
//	cat->Name = "Mila";
//	cat->Show();
//	cat->Sound();
//	cat->Type();
//
//	Pets * parrot = new Parrot();
//	parrot->Name = ("Kesha");
//	parrot->Show();
//	parrot->Sound();
//	parrot->Type();
//
//	Pets * hamster = new Hamster();
//	hamster->Name = ("Mr. Hamster");
//	hamster->Show();
//	hamster->Sound();
//	hamster->Type();
//
//
//	delete dog;
//	delete cat;
//	delete parrot;
//	delete hamster;
//	return 0;
//}