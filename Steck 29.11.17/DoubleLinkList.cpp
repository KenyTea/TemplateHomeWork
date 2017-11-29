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
void DoubleLinkList<T>::add(const T &value)
{
	if (first == NULL) {
		last = first = new Node<T>(value); // created new element
    }
	else {
		last->next = new Node<T>(value); // create next element
		last = last->next; //govorim chto last eto next
	}
}
