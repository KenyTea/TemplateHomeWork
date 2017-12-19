#include <iostream>
using namespace std;
/*������� �23
���� : ������������ ���
	������� ��� ��������������� ������ :
� ������ ���������� ��������������� � �������� ���� -
��� �� ������� ����� ������� �� ������ �� ����������� ������
(������, ������� � �.�.).���������� ��� ��������� ������ � ��� -
���������� ����.���������� ���������� ��������� ���������
�����������.��������� �������� ����������� �������� ��� ��
������������ ����������� �������.*/

namespace Alpha
{
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
}

namespace Betta
{
	template <class T>
	class DLList {  // ����� Double Link List
	public:
		Alpha::Node<T>*first, *last; // ��������� �� ������ � ���������

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





	template<class T>
	void DLList<T>::AddToHead(const T & value)
	{
		if (first == NULL) {
			last = first = new Alpha::Node<T>(value); // �������� �� �������
		}
		else {
			Alpha::Node <T> * temp = new Alpha::Node<T>(value);
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
			last = first = new Alpha::Node<T>(value); // �������� �� �������
		}
		else {
			Alpha::Node<T> *temp = new Alpha::Node<T>(value);  // ������ ����� �������
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
			std::cout << "ERROR!!! The List is empty" << endl;
		}
		else {
			for (Alpha::Node<T> * i = first; i != NULL; i = i->next)
				std::cout << i->value << " ";
		}
	}

}

int main() {

	Betta::DLList <int> * a = new Betta::DLList<int>();

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
