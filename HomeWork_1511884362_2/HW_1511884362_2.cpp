//#include <iostream>
//
//
//using namespace std;
///* Задание №2
//Реализуйте класс стека для работы с символами (символьный стек). Стек должен иметь
//фиксированный размер. Также реализуйте набор операций для работы со стеком:
//помещение символа в стек, выталкивание символа из стека, подсчет количества
//символов в стеке, проверку пустой ли стек, проверку полный ли стек, очистку стека,
//получение без выталкивания верхнего символа в стеке.
//Задание №2
//Измените стек из первого задания со статического типа на динамический (при нехватке
//свободного места нужно изменить размер внутреннего массива без потери данных).*/
//
//// Задание №2
//template <class T>
//class Stack {
//	T size = 5;
//	T *symbol;
//	T count = 0;
//
//public:
//	Stack();
//	~Stack();
//
//	void addSimbol(const T &);
//	void checkFullOrEmptyStack();
//	int Counter() {
//		return count;
//	}
//	T popStack();
//	T withoutPop();
//	void clearStack();
//	void show();
//};
//
//
//int main() {
//
//	Stack<char> a;
//
//	a.addSimbol('a');
//	a.addSimbol('b');
//	a.addSimbol('c');
//	a.addSimbol('d');
//	a.addSimbol('e');
//
//	a.show();
//	a.checkFullOrEmptyStack();
//	a.popStack();
//	a.show();
//	a.withoutPop();
//	a.show();
//
//	cout << a.Counter() << endl;
//
//
//	system("pause");
//	return 0;
//}
//
//
//template<typename T>
//Stack<T>::Stack() {
//	 symbol = new char[size];
//	
//}
//
//template<typename T>
//Stack<T>::~Stack() {
//	delete[] symbol;
//}
//
//template<class T>
//void Stack<T>::addSimbol(const T & value)
//{
//	if (count == size - 1) { // автоувеличение размера стека
//		size = size * 2;
//		T *Newsymbol = new T[size];
//		for (int i = 0; i < size; ++i) {
//			Newsymbol[i] = symbol[i];
//        }
//		delete symbol;
//		symbol = Newsymbol;
//}
//	
//	if (count < size) {
//		this->symbol[count] = value;
//		count++;
//
//	}
//	else { cout << "ERROR " << endl; }
//
//}
//
//template<class T>
//void Stack<T>::checkFullOrEmptyStack()
//{
//	if (count < 1) {
//		cout << "The Stack is empty" << endl;
//	}
//	else if (count > size) {
//		cout << "Stack is Full!" << endl;
//	}
//	else {
//		cout << "The Stack is not full" << endl;
//	}
//}
//
//template<class T>
//T Stack<T>::popStack()
//{
//	if (count >= 1) {
//		count--;
//	}
//	return symbol[count + 1];
//}
//
//template<class T>
//T Stack<T>::withoutPop()
//{
//	if (count > 0) {
//		return symbol[count - 1];
//	}
//	return '0';
//}
//
//template<class T>
//void Stack<T>::clearStack()
//{
//	count = 0;
//	size = 1;
//	delete symbol;
//	this->symbol = new char[size];
//}
//
//template<class T>
//void Stack<T>::show()
//{
//	cout << endl;
//	for (int i = 0; i < count; i++)
//		cout << symbol[i] << " ";
//	cout << endl;
//}
//
