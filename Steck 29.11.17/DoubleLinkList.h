#pragma once
#include "Node.h"
template<class T>
class DoubleLinkList
{
public:

	Node<T>  *first, *last;


	DoubleLinkList();
	~DoubleLinkList();

	void addToLast(const T &);

	void addToFerst(const T &);

	void show();
};

