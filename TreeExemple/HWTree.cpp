#include <iostream>
#include <time.h>
using namespace std;
class Item
{
public:
	int value;
	Item *left, *right;
	Item();
	~Item();
	Item(const int &);
};
class Tree
{
public:
	Item *root;
	Tree() {
		root = NULL;
	}
	~Tree() {

	}
	void add(const int &value, Item *temp)
	{
		if (temp == NULL) {
			temp = new Item(value);
		}
		else {
			if (temp->value < value) {
				if (temp->right == NULL) {
					temp->right = new Item(value);
				}
				else {
					add(value, temp->right);
				}
			}
			else if (temp->value >= value) {
				if (temp->left == NULL) {
					temp->left = new Item(value);
				}
				else {
					add(value, temp->left);
				}
			}
		}
	}
	void show(Item *temp)
	{
		{
			if (temp != NULL) {
				std::cout << temp->value << std::endl;
				show(temp->left);
				show(temp->right);
			}
		}
	}
};


int main()
{
	srand(time(NULL));
	Tree tree;
	tree.add(10, tree.root);
	for (size_t i = 0; i < 20; ++i) {
		tree.add(rand() % 100, tree.root);
	}
	tree.show(tree.root);
	system("pause");
	return 0;
}