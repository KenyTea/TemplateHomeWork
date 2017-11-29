#include "stdafx.h"
#include "DoubleLinkList.h"

template<class T>
DoubleLinkList <T>::DoubleLinkList()
{
	first = last = NULL;
}

template<class T>
DoubleLinkList <T>::~DoubleLinkList()
{
}

template<class T>
void DoubleLinkList<T>::addToLast(const T &value)
{
	if (first == NULL) {
		last = first = new Node<T>(value); // created new element
    }
	else {
		T * temp = new Node<T>(value); // create (next) new element
		last->next = temp
		temp->prev = last; // 
		last = temp; //govorim chto last eto teper next
	}
}

template<class T>
void DoubleLinkList<T>::addToFerst(const T &value)
{
	if (first == NULL) {
		first = last = new Node<T>(value); // created new element
	}
	else {
		T * temp = new Node<T>(value); // create (next) new element
		first->prev = temp;
			temp->next = first; // 
		first = temp; //govorim chto last eto teper next
	}
}

template<class T>
void DoubleLinkList<T>::show()
{
	if (first == NULL) {
		cout << "List is empty" << endl;
	}
	else {
		/*for (Node<T> * temp = first; temp != NULL; temp = temp->next){
		cout << temp->value << '\t'; 
		}
		cout << endl;*/

		Node<T>* temp = first;
		while (temp != Null) {
			cout << temp->value << '\t';
			teemp = temp->next;
		}
	}
}
