#include <iostream>

using namespace std;

/*������� �1
�������� ��������� ����� ����������� ������ ��� ������ � ������ ����������.
��������� ������� ���������� ��� �������� �������� ��� ����������:
AddToHead � ���������� �������� � ������;
AddToTail � ���������� �������� � �����;
DeleteFromHead � �������� �������� �� ������;
DeleteFromTail � �������� �������� �� ������;
DeleteAll � �������� ���� ���������;
Show � ����������� ���� ��������� ������ �� �����*/

/*������� �2
�������� � ����� �� ������� 1 ��������� �������:
������� �������� � �������� �������,
�������� �������� �� �������� �������,
����� ��������� �������� (������� ���������� ������� ���������� �������� � ������
������ ��� NULL � ������ �������),
����� � ������ ��������� �������� (������� ���������� ���������� ����������
��������� � ������ ������ ��� -1 � ������ �������),
��������� ������*/

template <class T>
class Node { // ����� ���
public:
	int value;
	Node *next, *prev; // ��������� �� ���������� � ���������
	Node() {} //  ����������� �� ���������
	Node(const T value) { // ������ ����������� � ������������ ����������
		this->value = value;
		prev = next = NULL;
	}
	~Node(); // ���������� �����������
};


template <class T>
class DLList {  // ����� Double Link List
public:
	Node<T>*first, *last; // ��������� �� ������ � ���������

	DLList() { // ����������� �����������
		first = last = NULL;
	}

	~DLList() {}; // ���������� �����������

	void AddToHead(const T & value); // �������� �����  ���������� � ������

	void AddToTail(const T & value); // �������� �����  ���������� � �����

	void DeleteFromHead(); // ������� �������� �������� �� ������

	void DeleteFromTail(); // ������� �������� �������� �� ������

	void DeleteAll(); // ������� �������� ���� ���������

	void Show(); // ����� �� �����

	/*������� 2*/

	void insertElement(int index, const T &value); // ��������� ����� ������� �������� � �������� �������

	void DeleteElementGivenPosition(int index); // ���������� ������ �������� �������� �� �������

	int FindElement(const T &value); // ��������� ����� ����� ��������� ��������

	int FindAndReplaceElement(const T &value, const T &value1); // ��������� ����� ����� � ������ ��������� ��������

	void ReverseList(); // ��������� ����� ��������� ������

};



int main() {

	DLList <int> * a = new DLList<int>();

	a->AddToTail(2);
	a->AddToTail(3);
	a->AddToTail(4);
	a->AddToTail(5);
	a->AddToTail(6);
	a->AddToHead(1);
	cout << "-----------------------------" << endl;
	a->Show();
	a->DeleteFromTail();
	cout << "-----------------------------" << endl;
	a->Show();
	cout << "-----------------------------" << endl;

	a->DeleteFromHead();
	cout << "-----------------------------" << endl;
	a->Show();
	cout << "-----------------------------" << endl;


	return 0;
}


template<class T>
void DLList<T>::AddToHead(const T & value)
{
	if (first == NULL) {
		last = first = new Node<T>(value); // �������� �� �������
	}
	else {
		Node <T> * temp = new Node<T>(value);
		first->prev = temp; // ���������, ��� ����� ������ ��������� ����� temp
		temp->next = first; // ���������, ��� � temp� next ��� first
		first = temp; // �������, ��� temp ������ first
		delete temp; // ������� temp (������)
	}
}

template<class T>
void DLList<T>::AddToTail(const T & value) // ���������� ������ ���������� � �����
{
	if (first == NULL) {
		last = first = new Node<T>(value); // �������� �� �������
	}
	else {
		Node<T> *temp = new Node<T>(value);  // ������ ����� �������
		last->next = temp; // �������������, ��� � ���������� �������� ��������� ������ temp 
		temp->prev = last; // ���������, ��� � temp ���������� ��������� �� last
		last = temp; // �������, ��� temp ������ ����� last
		delete temp; //  ������� temp (������ ������)
	}
}

template<class T>
void DLList<T>::DeleteFromHead() // ���������� �������� �������� �� ������
{
	first = first->next; // �������, ��� ��������� ������� ������ ������
}

template<class T>
void DLList<T>::DeleteFromTail() // ���������� �������� �������� �� ������
{
	last->prev->next = NULL; // �������, ��� ��������� ������� ����� ����
	last = last->prev; // �������, ��� ������������� ������� ������ ���������
}

template<class T>
void DLList<T>::DeleteAll()
{
	first = last = NULL;
}

template<class T>
void DLList<T>::Show()
{
	if (first == NULL) {
		cout << "ERROR!!! The List is empty" << endl;
	}
	else {
		for (Node<T> * temp = first; temp != NULL; temp = temp->next)
			cout << temp->value << " ";
	}
}

template<class T>
void DLList<T>::insertElement(int index, const T & value)
{
	int x = 0;
	for (Node<T> * temp = first; temp != NULL; temp = temp->next, x++) {
		cout << x + 1 << " - " << temp->value << endl;
		if (x == index - 2) {
			Node<T> *itemp = new Node<T>(value);
			itemp->next = temp->next;
			temp->next = itemp;
			itemp->prev = temp;
			delete itemp;
		}
	}   cout << endl;
}

template<class T>
void DLList<T>::DeleteElementGivenPosition(int index)
{
	int x = 0;
		for (Node<T> * temp = first; temp != NULL; temp = temp->next, x++) {
		if (x == index - 1) {
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
		}
	}
	x = 0;
	for (Node<T> * temp = first; temp != NULL; temp = temp->next, x++) {
		cout  << x + 1 << " - " << temp->value << endl;
	}
}

template<class T>
int DLList<T>::FindElement(const T & value)
{
	int x = 0;
	bool y = false;
		for (Node<T> * temp = first; temp != NULL; temp = temp->next, x++) {
		if (temp->value == value) {
			cout << "\tPosition #" << x + 1 << " - " << temp->value << endl;
			y = true;
		}
	}
	if (!y) { cout<< "ERROR   "  << value << " - NOT FOUND!  "; return NULL; }
	}

template<class T>
int DLList<T>::FindAndReplaceElement(const T & value, const T & value1)
{
	int x = 0, count = 1;
	bool y = false;
	for (Node<T> * temp = first; temp != NULL; temp = temp->next, x++) {
		if (temp->value == value) {
			temp->value = value1;
			cout << "\tPosition #" << x + 1 << " - " << temp->value << "  Counter = " << count << endl;
			y = true; count++;
		}
	}
	if (!y) { cout << "ERROR   " << value << " - NOT FOUND!\n\n"; return -1; }

	x = 0;
	for (Node<T> * temp = first; temp != NULL; temp = temp->next, x++) {
		cout << x + 1 << " - " << temp->value << endl;
	}
}

template<class T>
void DLList<T>::ReverseList()
{
	int x = 0;
	Node<T> * temp = first;
	first = last;
	last = temp;
	for (temp = first; temp != NULL; temp = temp->prev, x++) {
		cout << x + 1 << " - " << temp->value << endl;
	}cout << endl;
}
