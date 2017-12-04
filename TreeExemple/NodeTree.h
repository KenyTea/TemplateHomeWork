#pragma once
//#include "Tree.h"
template<class T>
class NodeTree
{
public:

	T value;
	NodeTree<T> * left, *right;
	NodeTree();
	~NodeTree();
	NodeTree(const T &);
	
};

