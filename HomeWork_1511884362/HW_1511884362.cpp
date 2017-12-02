#include <iostream>


using namespace std;
/*���������� ����� ����� ��� ������ � ��������� (���������� ����). ���� ������ �����
������������� ������. ����� ���������� ����� �������� ��� ������ �� ������:
��������� ������� � ����, ������������ ������� �� �����, ������� ����������
�������� � �����, �������� ������ �� ����, �������� ������ �� ����, ������� �����,
��������� ��� ������������ �������� ������� � �����.
������� �2
�������� ���� �� ������� ������� �� ������������ ���� �� ������������ (��� ��������
���������� ����� ����� �������� ������ ����������� ������� ��� ������ ������).*/

template <class T>
class Stack {
	const int size = 5;
	T symbol[5];
	T count;

public:
	Stack();
	~Stack();

	void addSimbol(const T);
	void checkFullOrEmptyStack();
	int Counter() {
	     return count;
	}
	T popStack();
	T withoutPop();
	void clearStack();
	void show();
};


int main() {

	Stack<char> a;

	a.addSimbol('a');
	a.addSimbol('b');
	a.addSimbol('c');
	a.addSimbol('d');
	a.addSimbol('e');

	a.show();
	a.checkFullOrEmptyStack() ;
	a.popStack();
	a.show();
	a.withoutPop();
	a.show();

	cout << a.Counter() << endl;
	

	system("pause");
	return 0;
}


template<typename T>
Stack<T>::Stack(){
	
	count = 0;
}

template<typename T>
Stack<T>::~Stack() {
}

template<class T>
void Stack<T>::addSimbol(const T value)
{
	if (count < size) {
		this->symbol[count] = value;
		count++;
		
	}
	else { cout << "ERROR " << endl; }

}

template<class T>
void Stack<T>::checkFullOrEmptyStack()
{
	if (count < 1) {
		cout << "The Stack is empty" << endl;
	}
	else if (count > size) {
		cout << "Stack is Full!" << endl;
	}
	else {
		cout << "The Stack is not full" << endl;
	}
}

template<class T>
T Stack<T>::popStack()
{
	if (count >= 1) {
		count--;
	}
	return symbol[count + 1];
}

template<class T>
T Stack<T>::withoutPop()
{
	if (count > 0) {
		return symbol[count - 1];
	}
	return '0';
}

template<class T>
void Stack<T>::clearStack()
{
	count = 0;
}

template<class T>
void Stack<T>::show()
{
	cout << endl;
	for (int i = 0; i < count; i++)
		cout << symbol [i] << " ";
	cout << endl;
}

