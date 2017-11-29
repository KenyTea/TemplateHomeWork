#include "stdafx.h"
#include "Node.h"

template<class T>
Node<T>::Node()
{
}

template<class T>
Node<T>::Node(const T &value)
{
	this->value = value;
	prev = next = NULL;// govorim chto net ni nachalo ni conca
 }

template<class T>
Node<T>::~Node()
{
}
