#pragma once

class Node
{
public:
	int value;
	Node  * prev, *next;
	Node();
	Node(const int &);
	~Node();
};

