// Agrigation_Compothish.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

// INNER class

using namespace std;
#include <iostream>
using namespace  std;



class List {
public:
	class Element {
	public:
		int value;
		Element *next;
		Element() {}
		Element(const int value) {
			this->value = value;
			next = NULL;
		}
		~Element() {}


	};



	Element *first;

	List() {
		first = NULL;
	}
	~List() {}

	void AddToList(const int &value) {
		if (first == NULL) {
			first = new Element(value);
		}
		else {
			Element *temp = first;
			while (temp->next != NULL) {
				temp = temp->next;
			}
			temp->next = new Element(value);

		}
	}

	void show() {
		int i = 0;
		if (first == NULL) {
			cout << "List is empty" << endl;
		}
		else {
			cout << "\n";
			for (Element * temp = first; temp != NULL; temp = temp->next, i++) {
				cout << "\t" << i + 1 << " - " << temp->value << "\n";
			}cout << "\n";
		}
	}

};




void main() {
	List  *a = new List;

	a->AddToList(5);
	a->AddToList(7);
	a->AddToList(9);
	a->AddToList(3);
	a->show();
}
