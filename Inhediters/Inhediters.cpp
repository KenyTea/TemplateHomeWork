// Inhediters.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

class Human {
public:
	char name[20];
	Human() {
		cout << "Constructor Human" << endl;
	}
	~Human() {

		cout << "~Destructor Human" << endl;
	}
};
class Student  {
public:
	Student() {
		cout << "Constructor Student" << endl;
	}
	~Student() {

		cout << "~Destructor Student" << endl;
	}


};

class Polismen :public Student, public Human {
public:
	Polismen() {
		cout << "Constructor Polismen" << endl;
	}
	~Polismen() {

		cout << "~Destructor Polismen" << endl;
	}


};

int main()
{
	Polismen *P = new Polismen();
	delete P;
    return 0;
}

