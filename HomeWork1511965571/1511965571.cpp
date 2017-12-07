#include <iostream>

using namespace std;

/*«адание є1
—оздайте шаблонный класс двусв€зного списка дл€ работы с целыми значени€ми.
“ребуетс€ создать реализации дл€ типичных операций над элементами:
AddToHead Ц добавление элемента в голову;
AddToTail Ц добавление элемента в хвост;
DeleteFromHead Ц удаление элемента из головы;
DeleteFromTail Ц удаление элемента из хвоста;
DeleteAll Ц удаление всех элементов;
Show Ц отображение всех элементов списка на экран*/

template <class T>
class Node { // клфсс Ќод
public:
	int value;
	Node *next, *prev; // указатели на предидущий и следующий
	Node() {} //  конструктор по умолчанию
	Node(const T value) { // второй конструктор с принимаемыми значени€ми
		this->value = value;
		prev = next = NULL;
	}
	~Node(); // деструктор поумолчанию
};


template <class T>
class DLList {  // класс Double Link List
public:
	Node<T>*first, *last; // указатели на первый и последний

	DLList() { // конструктор поумолчанию
		first = last = NULL;
	}

	~DLList() {}; // деструктор поумолчанию

	void AddToHead(const T & value); // объ€вили метод  добавлени€ в начало

	void AddToTail(const T & value); // объ€вили метод  добавлени€ в конец

	void DeleteFromHead(); // об€вили удаление элемента из начала

	void DeleteFromTail(); // об€вили удаление элемента из хвоста

	void DeleteAll(); // об€вили удаление всех элементов

	void Show(); // вывод на экран
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
		last = first = new Node<T>(value); // проверка на пустоту
	}
	else {
		Node <T> * temp = new Node<T>(value);
		first->prev = temp; // указываем, что перед первым элементам стоит temp
		temp->next = first; // указываем, что у tempј next это first
		first = temp; // говорим, что temp теперь first
		delete temp; // удал€ем temp (утечка)
	}
}

template<class T>
void DLList<T>::AddToTail(const T & value) // реализаци€ метода добавлени€ в конец
{
	if (first == NULL) {
		last = first = new Node<T>(value); // проверка на пустоту
	}
	else {
		Node<T> *temp = new Node<T>(value);  // создаЄм новый элемент
		last->next = temp; // переуказываем, что у последнего элемента следующий темерь temp 
		temp->prev = last; // указываем, что у temp пердидущий указывает на last
		last = temp; // говорим, что temp теперь будет last
		delete temp; //  удал€ем temp (утечка пам€ти)
	}
}

template<class T>
void DLList<T>::DeleteFromHead() // реализаци€ удаление элемента из начала
{
	first = first->next; // говорим, что следующий элемент теперь первый
}

template<class T>
void DLList<T>::DeleteFromTail() // реализаци€ удаление элемента из хвоста
{
	last->prev->next = NULL; // говорим, что последний елемент равен нулю
	last = last->prev; // говорим, что предпоследний элемент теперь последний
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
