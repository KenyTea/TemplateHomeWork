#include "stdafx.h"
#include <iostream>
using namespace std;

////#1
//class Employer {
//public:
//	Employer() {}
//	~Employer() {}
//	virtual void Print(){}
//};
//
//class President : public Employer {
//public:
//	void Print() override {
//		cout << "I'm BOSS" << endl;
//		cout << endl;
//	}
//};
//
//class Manager : public Employer {
//public:
//	void Print() override {
//		cout << "I'm midl class in the Corporation" << endl;
//		cout << endl;
//	}
//};
//
//class Worker : public Employer {
//public:
//	void Print() final{
//		cout << "I'm only work for food" << endl;
//		cout << endl;
//	}
//};

//#2
class Figure {
public:
	Figure() {}
	virtual ~Figure() {}
	virtual float GetArea() = 0;
};
class Rectangl : public Figure {
	float width, hight;
public:
	Rectangl(float width, float hight)  {
		this->width = width;
		this->hight = hight;
	}
	float GetArea()  {
		return width * hight;
	}
};

class Circle : public Figure {
	float radius;
public:
	Circle (float radius) {
		this->radius = radius;
		
	}
	float GetArea()  {
		return radius * radius * 3.14;
	}
};

int main(){
	// #1
	/*President president;
	president.Print();

	Manager manager;
	manager.Print();

	Worker worker;
	worker.Print();*/

	//#2

	Rectangl *rectangl = new Rectangl(10, 5);

	cout << rectangl->GetArea() << endl;

	Circle * circle = new Circle(15);

	cout << circle->GetArea() << endl;
	// массив сылок на указатели абстрактного класса
	Figure **arr = new Figure *[2];
	// присвоение объектов разных классов
	arr[1] = new Rectangl(3, 2);
	arr[0] = new Circle(2);
	for (int i = 0; i < 2; ++i) {
		cout << arr[i]->GetArea() << endl;
		delete arr[i];
	}

	delete rectangl;
	delete circle;
	delete[] arr;
    return 0;
}

