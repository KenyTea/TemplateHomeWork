// 28.11.2017.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
template <class T>
class Stack {
	T *stack;
     const int size = 1048576;;
	int top;
public:

	Stack(); // konstruktor
   ~Stack(); // destruktor

   void push(const T& t); // add 

   T pop(); // delete
};

template<class T>
Stack<T>::Stack() // konstruktor  realbzaciya vinesena za class
{
	stack = new T[size];
	top = 0;
}

template<class T>
Stack<T>::~Stack()  // destruktor realbzaciya vinesena za class
{
	delete[] stack;
}


template<class T>
void Stack<T>::push(const T & t)
{
	if (top + 1 <= size) {
		stack[++top] = t;
	}

}

template<class T>
T Stack<T>::pop()
{
	if (top > 0) {
		top--;
	return stack[top + 1]; // vozvrashaem posledniy element
	}
}







int main()
{

	Stack<int> stack;
	
	stack.push(2);
	stack.push(3);
	stack.push(4);
	stack.push(5);

	cout << stack.pop() << endl;
	cout << stack.pop() << endl;
	cout << stack.pop() << endl;
	cout << stack.pop() << endl;
    return 0;
}

