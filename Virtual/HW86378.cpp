#include "stdafx.h"

class HomePets {
public:
	string Name;
	virtual void Sound() {
	}

	virtual void Show() {
	}

	virtual void Type() {
	}
	HomePets(){}
	virtual ~HomePets(){}
};

class Dog : public HomePets {
public:
	
	void Sound() {
		cout << "Gav Gav" << endl;
	}
	
	virtual void Show() {
		
		cout << Name << endl;
	}
	virtual void Type() {

		cout << "Bishon" << endl;
	}
	
	~Dog() {}
};

class Cat : public HomePets {
public:
	void Sound() {
		cout << "Myu" << endl;
	}

	virtual void Show() {
		
		cout << Name << endl;
	}
	virtual void Type() {

		cout << "Garden type" << endl;
	}

};

int main() {
	HomePets * dog = new Dog();
	dog->Name = "Felisity";
	dog->Sound();
	dog->Show();
	dog->Type();
	cout << "===============================" << endl;
	HomePets * cat = new Cat();
	cat->Name = "Mila";
	cat->Sound();
	cat->Show();
	cat->Type();

	delete dog;
	return 0;
}