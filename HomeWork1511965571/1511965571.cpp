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

	void AddToTail(const T &value); // объ€вили метод  добавлени€ в конец

	void DeleteFromTail(); // // об€вили удаление элемента из хвоста
};
int main() {


	return 0;
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
	}
}

template<class T>
void DLList<T>::DeleteFromTail() // реализаци€ удаление элемента из хвоста
{
	last->prev->next = NULL;
	last = last->prev;
}
