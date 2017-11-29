#include "stdafx.h"
#include "DoubleLinkList.h"
using namespace std;

DoubleLinkList ::DoubleLinkList()
{
	first = last = NULL;
}

DoubleLinkList ::~DoubleLinkList()
{
}


void DoubleLinkList::addToLast(const int &value)
{
	if (first == NULL) {
		last = first = new Node(value); // created new element
    }
	else {
		Node * temp = new Node(value); // create (next) new element
		last->next = temp;
		temp->prev = last; // 
		last = temp; //govorim chto last eto teper next
	}
}


void DoubleLinkList::addToFerst(const int &value)
{
	if (first == NULL) {
		first = last = new Node(value); // created new element
	}
	else {
		Node * temp = new Node(value); // create (next) new element
		first->prev = temp;
			temp->next = first; // 
		first = temp; //govorim chto last eto teper next
	}
}


void DoubleLinkList::show()
{
	if (first == NULL) {
		cout << "List is empty" << endl;
	}
	else {
		/*for (Node * temp = first; temp != NULL; temp = temp->next){
		cout << temp->value << '\t'; 
		}
		cout << endl;*/

		Node * temp = first;
		while (temp != NULL) {
			cout << temp->value << endl;
			temp = temp->next;
		}
	}
}
