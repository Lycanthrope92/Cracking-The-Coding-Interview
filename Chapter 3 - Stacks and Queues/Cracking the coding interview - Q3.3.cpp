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


template<typename T> class setOfStacks {
public:
	setOfStacks(int x ){
		head =NULL;
		treshold = x;
		count = 0;
	}

	void push( T data){
		if ( head == NULL || count == treshold )
		{
			stack<T> *b = new stack<T>();
			b->push(data);
			list<stack<T>> *a = new list<stack<T>>;
			a->item = *b;
			a->next = head;
			head = a;
			if ( count == treshold ){
				count = 1;
			}else{
				count++;
			}

		}
		else
		{
			(head->item).push(data); count++;
		}

	}

	T pop() {
		if ( head == NULL ) return INT_MIN;
		if ( count == 1 ) {
			list<stack<T>> *temp = head;
			head =head->next;
			T data = (temp->item).pop();
			delete temp;
			if ( head == NULL )
				count = 0;
			else
				count = treshold;

			return data;
		}
		else
		{
			count--;
			return (head->item).pop();
		}


	}

private:
	list<stack<T>> *head;
	int count;
	int treshold;
};





int main()
{
	setOfStacks<int> *a = new setOfStacks<int>(4);
	a->push(1);
		a->push(2);
			a->push(3);
	a->push(4);
		a->push(5);
		int x = a->pop();
	return 0;
}