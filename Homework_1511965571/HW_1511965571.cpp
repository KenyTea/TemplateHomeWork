//#include <iostream>
//using namespace std;
///*—оздайте шаблонный класс двусв€зного списка дл€ работы с целыми значени€ми.
//“ребуетс€ создать реализации дл€ типичных операций над элементами:
//AddToHead Ц добавление элемента в голову;
//AddToTail Ц добавление элемента в хвост;
//DeleteFromHead Ц удаление элемента из головы;
//DeleteFromTail Ц удаление элемента из хвоста;
//DeleteAll Ц удаление всех элементов;
//Show Ц отображение всех элементов списка на экран*/
//
//
//template<class T>
//class Node {
//public:
//	T value;
//	Node<T> *prev, *next;  //”казатели на адреса следующего и предыдущего элементов списка
//	Node(T);
//	~Node() {
//		delete prev, next;
//	}
//};
//
//template<class T>
//class List {
//public:
//    Node *head, *tail; //”казатели на адреса начала списка и его конца
//	List() { //  конструктор по умолчани€ (инециализируем нул€ми)
//		Head = NULL;
//		Tail = NULL;
//	}
//	~List() {
//	
//	}
//
//	void Add(T value);
//	void Show();
//
//};
//int main() {
//
//
//
//	system("pause");
//	return 0;
//}
//
//template<class T>
//void List<T>::Add(T value)
//{
//	T * temp = new T;
//	temp
//}
//
//template<class T>
//Node<T>::Node(T value)
//{
//	this->value = value;
//	Head = NULL; Tali = NULL;
//}
