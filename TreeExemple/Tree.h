#pragma once
//#include "NodeTree.h"
template<class T>
class Tree
{
public:
	NodeTree<T> * root; // kotnevoy element (tochka vhoda)
	Tree();
	~Tree();
	void add(const T &, NodeTree<T> &);

	void show(NodeTree<T>&);
};

