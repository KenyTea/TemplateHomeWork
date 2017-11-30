#include "stdafx.h"
#include "NodeTree.h"

template<class T>
NodeTree<T>::NodeTree()
{
	left = right = NULL;
}

template<class T>
NodeTree<T>::~NodeTree()
{
}

template<class T>
NodeTree<T>::NodeTree(const T &value):NodeTree()
{
	this->value = value;
}

