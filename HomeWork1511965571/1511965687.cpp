#include <iostream>

using namespace std;

/*Задание №1
Создайте шаблонный класс двусвязного списка для работы с целыми значениями.
Требуется создать реализации для типичных операций над элементами:
AddToHead – добавление элемента в голову;
AddToTail – добавление элемента в хвост;
DeleteFromHead – удаление элемента из головы;
DeleteFromTail – удаление элемента из хвоста;
DeleteAll – удаление всех элементов;
Show – отображение всех элементов списка на экран*/

/*Задание №2
Добавить в класс из задания 1 следующие функции:
вставка элемента в заданную позицию,
удаление элемента по заданной позиции,
поиск заданного элемента (функция возвращает позицию найденного элемента в случае
успеха или NULL в случае неудачи),
поиск и замена заданного элемента (функция возвращает количество замененных
элементов в случае успеха или -1 в случае неудачи),
переворот списка*/

template <class T>
class Node { // клфсс Нод
public:
	int value;
	Node *next, *prev; // указатели на предидущий и следующий
	Node() {} //  конструктор по умолчанию
	Node(const T value) { // второй конструктор с принимаемыми значениями
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

	void AddToHead(const T & value); // объявили метод  добавления в начало

	void AddToTail(const T & value); // объявили метод  добавления в конец

	void DeleteFromHead(); // обявили удаление элемента из начала

	void DeleteFromTail(); // обявили удаление элемента из хвоста

	void DeleteAll(); // обявили удаление всех элементов

	void Show(); // вывод на экран

	/*Задание 2*/

	void insertElement(int index, const T &value); // объявляем метод вставка элемента в заданную позицию

	void DeleteElementGivenPosition(int index); // объявление метода удаления элемента по позиции

	int FindElement(const T &value); // объявляем метод поиск заданного элемента

	int FindAndReplaceElement(const T &value, const T &value1); // объявляем метод поиск и замена заданного элемента

	void ReverseList(); // объявляем метод переворот списка

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
		temp->next = first; // указываем, что у tempА next это first
		first = temp; // говорим, что temp теперь first
		delete temp; // удаляем temp (утечка)
	}
}

template<class T>
void DLList<T>::AddToTail(const T & value) // реализация метода добавления в конец
{
	if (first == NULL) {
		last = first = new Node<T>(value); // проверка на пустоту
	}
	else {
		Node<T> *temp = new Node<T>(value);  // создаём новый элемент
		last->next = temp; // переуказываем, что у последнего элемента следующий темерь temp 
		temp->prev = last; // указываем, что у temp пердидущий указывает на last
		last = temp; // говорим, что temp теперь будет last
		delete temp; //  удаляем temp (утечка памяти)
	}
}

template<class T>
void DLList<T>::DeleteFromHead() // реализация удаление элемента из начала
{
	first = first->next; // говорим, что следующий элемент теперь первый
}

template<class T>
void DLList<T>::DeleteFromTail() // реализация удаление элемента из хвоста
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
