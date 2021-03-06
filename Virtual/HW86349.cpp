 //virtual.cpp : defines the entry point for the console application.


#include "stdafx.h"
#include <iostream>
using namespace std;


/*Задание №1
Создать базовый класс список.
Реализовать на базе списка стек и очередь с виртуальными
функциями вставки и вытаскивания.*/

class list {
public:
	list() {}
	virtual ~list() {}
	virtual int remove() = 0;
	virtual void add(const int &) = 0;
};

class Stack :public list {
	int *stack;
	const int size = 1048576;
	int top;
public:
	Stack() {
		stack = new int[size];
		top = 0;
	}
	~Stack() {
		delete[] stack;
	}
	void push(const int &value) {
		if (top + 1 <= size) {
			stack[++top] = value;
		}
	}
	int pop() {
		if (top > 0) {
			top--;
		}
		return stack[top + 1];
	}
	void add(const int &value) {
		push(value);
	}
	int remove() {
		return pop();
	}
};

class Queue :public list
{
	int *queue;
	const int size = 1048576;
	int first, last, cnt;
public:
	Queue() {
		queue = new int[size];
		first = last = cnt = 0;
	}
	~Queue() {
		delete[] queue;
	}
	void enqueue(const int &value) {
		if (cnt < size) {
			queue[last++] = value;
			++cnt;
			if (last > size) {
				last -= size + 1;
			}
		}
	}
	int dequeue() {
		if (cnt > 0) {
			int temp = queue[first++];
			--cnt;
			if (first > size) {
				first -= size + 1;
			}
			return temp;
		}
	}
	int remove() {
		return dequeue();
	}
	void add(const int &value) {
		enqueue(value);
	}
};
int main()
{
	/*a **a = new a*[2];
	a[0] = new b();
	a[1] = new a();
	for (int i = 0; i < 2; i++) {
	a[i]->say();
	}*/
	/*a *b = new b();
	delete b;*/
	/*iprogrammer *a = new worker();*/

	list *stack = new Stack();
	list *queue = new Queue();
	stack->add(1);
	stack->add(2);
	cout << stack->remove() << endl;
	cout << stack->remove() << endl;
	queue->add(1);
	queue->add(2);
	cout << queue->remove() << endl;
	cout << queue->remove() << endl;
	delete stack;
	delete queue;
	return 0;
}
