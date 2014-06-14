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

template<typename T> void move_disks ( stack<T> **s, stack<T>**d, stack<T> **b, int N){
	if ( N == 1 ) {
		(*d)->push((*s)->pop());
		return;
	}
	else {
		move_disks ( s, b, d, N-1 );
		move_disks ( s, d, b, 1 );
		move_disks ( b, d, s, N-1);
		return;
	}

}

template<typename T> void towers_of_hanoi ( stack<T> **s, stack<T> **d, int N) {
	if ( N < 1 || (*s)->isEmpty() || !(*d)->isEmpty()) return;
	stack<T> *b = new stack<T>();
	move_disks( s, d, &b, N);
	return;
}




int main()
{
	stack<int> *a = new stack<int>();
	a->push(5);
	a->push(4);
	a->push(3);
	a->push(2);
	a->push(1);

	stack<int> *b = new stack<int>();
	towers_of_hanoi ( &a, &b, 5);

	return 0;
}