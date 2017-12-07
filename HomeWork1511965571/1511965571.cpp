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

	void AddToTail(const T &value); // �������� �����  ���������� � �����

	void DeleteFromTail(); // // ������� �������� �������� �� ������
};
int main() {


	return 0;
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
	}
}

template<class T>
void DLList<T>::DeleteFromTail() // ���������� �������� �������� �� ������
{
	last->prev->next = NULL;
	last = last->prev;
}
