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
		for (Node<T> * i = first; i != NULL; i = i->next)
			cout << i->value << " ";
	}
}
