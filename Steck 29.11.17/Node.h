#pragma once
template<class T>
class Node
{
public:
	T value;
	Node <T> * prev, *next;
	Node();
	Node(const T &);
	~Node();
};

