#pragma once
#include "Node.h"
template<class T>
class DoubleLinkList
{
public:

	Node<T>  *first, *last;


	DoubleLinkList();
	~DoubleLinkList();

	void add(const T &);

};

