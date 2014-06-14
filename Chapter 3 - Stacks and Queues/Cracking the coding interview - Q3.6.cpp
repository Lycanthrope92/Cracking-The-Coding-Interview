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

template<typename T> void f_rec (stack<T> **buffer, T &poppedItem ) {
	if ( (*buffer)->isEmpty() ) {
		(*buffer)->push (poppedItem);
		return;
	}
	else if ( poppedItem < (*buffer)->topItem() ) {
		(*buffer)->push(poppedItem);
		return;
	}
	else
	{
		T temp = (*buffer)->pop();
		f_rec( buffer, poppedItem );
		(*buffer)->push(temp);
		return;
	}
}


template<typename T> void sort_ascending ( stack<T> **myS) {
	if ( (*myS)->isEmpty() )
		return;
	T temp = (*myS)->pop();
	if ( (*myS)->isEmpty() ) {
		(*myS)->push(temp);
		return;
	}
	stack<T> *buffer = new stack<T>;
	buffer->push(temp);
	while ( !(*myS)->isEmpty() ) {
		T temp = (*myS)->pop();
		f_rec (&buffer, temp);
	}

	while ( !buffer->isEmpty() ){
		(*myS)->push( buffer->pop() );
	}

	return;

}




int main()
{
	stack<int> *myS = new stack<int>();
	
	myS->push(1);
	myS->push(2);
	myS->push(3);
	myS->push(4);
	myS->push(5);
	sort_ascending(&myS);

	return 0;
}