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
	stack() { top = NULL; min = NULL;}

	void push ( T x )
	{
		list<T> *temp = new list<T>;
		temp->item = x;
		temp->next = top;
		top = temp;

		if ( min == NULL || top->item < *min )
			min = &(top->item);
	}

	T pop ()
	{
		if ( this->isEmpty() )
			return INT_MIN;

		list<T> *temp = top;
		T popedItem = top->item;
		top = top->next;

		if ( min == &(temp->item) )
		{
			min = &(top->next->item);
			for ( list<T>* it = top->next->next; it != NULL; it =it->next )
			{
				if ( it->item < *min )
					min = &(it->item);
			}

		}
		delete temp;
		
		return popedItem;
	}

	T *pointerMin()
	{
		return min;
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
	T* min;
};







int main()
{
	stack<int> *myStack = new stack<int>();
	myStack->push(0);
	myStack->push(1);
	myStack->push(2);
	myStack->push(3);
	myStack->push(-1);


	int poped;
	poped = myStack->pop();


	return 0;
}