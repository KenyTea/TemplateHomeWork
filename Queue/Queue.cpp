// Queue.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

template<class T>
class Queue {
	T * queue;
	const int size = 1048576;
		int first, last, cnt;
public:
	Queue();
	~Queue();
	void enqueue(const T&);

	T dequeue();

};

int main()
{
	Queue<int> queue;
	queue.enqueue(1);
	queue.enqueue(2);
	queue.enqueue(3);
	queue.enqueue(4);


	cout << queue.dequeue() << endl;
	cout << queue.dequeue() << endl;
	cout << queue.dequeue() << endl;
	cout << queue.dequeue() << endl;



    return 0;
}

template<class T>
Queue<T>::Queue()
{
	queue = new T[size];
	first = last = 0;
}

template<class T>
Queue<T>::~Queue()
{
	delete[] queue;
}

template<class T>
void Queue<T>::enqueue(const T &t)
{
	if (cnt < size) {
		queue[last++] = t;
		++cnt;
		if (last > size) {
			last -= size + 1;
		}
	}
}

template<class T>
T Queue<T>::dequeue()
{
	if (cnt > 0) {
		T temp = queue[first++];
		--cnt;
		if (first > size) {
			first -= size + 1;

		}
        return temp;
	}
}
