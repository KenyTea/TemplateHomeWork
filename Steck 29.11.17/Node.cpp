#include "stdafx.h"
#include "Node.h"


Node::Node()
{
}


Node::Node(const int &value)
{
	this->value = value;
	prev = next = NULL;// govorim chto net ni nachalo ni conca
 }


Node::~Node()
{
}
