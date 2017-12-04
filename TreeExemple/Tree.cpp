#include "stdafx.h"
#include "Tree.h"


 template<class T>
Tree<T>::Tree()
{
	root = NULL;
}

template<class T>
Tree<T>::~Tree()
{
}

template<class T>
inline void Tree<T>::add(const T &value, NodeTree<T> &root = this->root)
{
	if (root == NULL) {
		root = new NodeTree<T>(value);
	}
	else {
		NodeTree<T> * temp = root;
		if (temp->value < value) {
			if (temp->right == NULL)
				temp->right = new NodeTree<T>(value);
			else {
				add(value, root->right);
			}
		}
		else if (root->value >= value) {
			if (root->left == NULL) {
				root->left = new NodeTree<T>(value);
			}
		}
	}
}

template<class T>
inline void Tree<T>::show(NodeTree<T> &root = this->root)
{
	if (root != NULL) {
		cuot << root->value << endl;
		show(root->left);
		show(root->right);
	}
}
