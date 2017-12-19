#include <iostream>
using namespace std;
/*Встреча №23
Тема : Пространство имён
	Задание для самостоятельной работы :
В рамках предыдущих самостоятельных и домашних зада -
ний вы создали набор классов по работе со структурами данных
(списки, деревья и т.д.).Разместите уже созданные классы в про -
странствах имен.Продумайте правильную структуру созданных
пространств.Используя механизм пространств напишите код по
тестированию полученного решения.*/

namespace Alpha
{
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
}

namespace Betta
{
	template <class T>
	class DLList {  // класс Double Link List
	public:
		Alpha::Node<T>*first, *last; // указатели на первый и последний

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
	};





	template<class T>
	void DLList<T>::AddToHead(const T & value)
	{
		if (first == NULL) {
			last = first = new Alpha::Node<T>(value); // проверка на пустоту
		}
		else {
			Alpha::Node <T> * temp = new Alpha::Node<T>(value);
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
			last = first = new Alpha::Node<T>(value); // проверка на пустоту
		}
		else {
			Alpha::Node<T> *temp = new Alpha::Node<T>(value);  // создаём новый элемент
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
