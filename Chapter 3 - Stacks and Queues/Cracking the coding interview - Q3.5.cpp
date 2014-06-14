#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cmath>
#include <limits>
#include <algorithm>

#include <cstdlib>
#include <fstream>
#include <sstream>
#include <signal.h>
#include <utility>
using namespace std;

template <typename T> struct list {
	T item;
	list<T> *next;
};

template <typename T> class stack {
public:
	stack() { top = NULL; }
	
	void push ( T x )
	{
		list<T> *temp = new list<T>;
		temp->item = x;
		temp->next = top;
		top = temp;
	}

	T pop ()
	{
		if ( this->isEmpty() )
			return INT_MIN;
		
		list<T> *temp = top;
		T popedItem = top->item;
		top = top->next;
		delete temp;
		return popedItem;
	}

	T topItem ()
	{
		if ( this->isEmpty() )
			return INT_MIN;
		
		return top->item;
	}


	bool isEmpty()
	{
		return top == NULL;
	}

private:
	list<T> *top;
};


template<typename T> class queue {
public:
	queue()	{
		front = new stack<T>();
		rear = new stack<T>();
	}

	void enQueue (T x ) {
		if ( rear->isEmpty()  && !front->isEmpty() )
			while ( !front->isEmpty() )
				rear->push( front->pop() );

		rear->push(x);
	}

	T deQueue() {
		if ( rear->isEmpty() && front->isEmpty() )
			return INT_MIN;

		if ( !rear->isEmpty() && front->isEmpty() )
			while ( !rear->isEmpty() )
				front->push( rear->pop() );

		T data = front->pop();
		return data;
	}
	T frontItem() {
		if ( front->isEmpty() && rear->isEmpty() )
			return INT_MIN;
		if ( !rear->isEmpty() && front->isEmpty() )
			while ( !rear->isEmpty() )
				front->push( rear->pop());
		return front->topItem();
	}

private:
	stack<T> *front;
	stack<T> *rear;
};





int main()
{
	queue<int> *myQ = new queue<int>();
	myQ->enQueue(1);
	myQ->enQueue(2);
	myQ->enQueue(3);
	myQ->enQueue(4);
	int x = myQ->deQueue();
	x = myQ->deQueue();
	x = myQ->deQueue();
	x = myQ->frontItem();

	return 0;
}