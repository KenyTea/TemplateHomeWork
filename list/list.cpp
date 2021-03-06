// list.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
template<class T>
class Element {
	T value;

	Element<T> *next;
public:
	Element(T);
	~Element();
};

template<class T>
Element<T>::Element(T value) {
	this->value = value;
	next = NULL;
}

template<class T>
class List {
	void addToElements(Element <T>, const T& t);
	Element <T> * first;
public:
	List();
	~List();
	void add(const T&);
	//void addByOneFunction(Element<T>=first, const T &);
};

int main()
{
    return 0;
}

template<class T>
void List<T>::addToElements(Element<T> element, const T & t)
{
	if (element == NULL) {
		element = new Element(t)
	}
	else {
		addToElements(element->next, t);
	}
}

template<class T>
List<T>::List()
{
	first = NULL;
}

template<class T>
List<T>::~List()
{
	delete first;
}

template<class T>
void List<T>::add(const T &t)
{
	if (first == NULL) {
		first = new Element (t);
}
	else {
		addToElements(first->next, t);
	}
}

//template<class T>
//void List<T>::addByOneFunction(Element<T> element= first, const T &)
//{
//	if (element == NULL) {
//		element = new Element(t)
//	}
//	else {
//		addToElements(element->next, t);
//	}
//
//}
