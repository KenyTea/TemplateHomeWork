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
		cout << " Bug " << endl;
	}
	
	virtual void Show() {
		
		cout << Name << endl;
	}
	virtual void Type(string &Type) {

		cout << "Bishon" << endl;
	}
	
};

class Cat : public HomePets {
public:
	void Sound() {
		cout << " MYU " << endl;
	}

	virtual void Show() {
		
		cout << Name << endl;
	}
	virtual void Type() {

		cout << "Veslouhiy" << endl;
	}

};

int main() {
	HomePets * dog = new Dog();
	dog->Name = "Felisity";
	dog->Sound();
	dog->Show();


	return 0;
}