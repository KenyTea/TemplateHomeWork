#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

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
	
	virtual void Show(string &Name) {
		this->Name = Name;
		cout << Name << endl;
	}
	virtual void Type(string &Type) {

		cout << "Bishon" << endl;
	}
	
};

class Cat : public HomePets {
public:
	string Myu;
	string Type;
	void Sound() {
		cout << "Bug" << endl;
	}
};