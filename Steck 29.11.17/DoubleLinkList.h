#pragma once

#include "Node.h"

class DoubleLinkList
{
public:
	int value;
	 Node *first, *last;


	DoubleLinkList();
	~DoubleLinkList();

	void addToLast(const int &);

	void addToFerst(const int &);

	void show();
};

