// Steck 29.11.17.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "DoubleLinkList.h"
using namespace std;

//List2

int main()
{

	DoubleLinkList *a = new DoubleLinkList();
	a->addToLast(5);
	a->addToLast(6);
	a->addToFerst(4);
	a->show();
	delete a;
    return 0;
}

