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
	queue(){
		front = NULL;
		rear = NULL;
	}

	void enQueue ( T x ){
		list<T> *temp = new list<T>;
		temp->item = x;
		temp->next = NULL;
		if ( this->isEmpty() ){
			front =temp;
			rear = temp;
		}
		else
		{
			rear->next = temp;
			rear = temp;
		}


	}

	T deQueue() {
		if ( this->isEmpty() )
			return INT_MIN;
		list<T> *temp = front;
		T data = front->item;
		if ( front == rear ){
			front = NULL;
			rear = NULL;
		}
		else
			front = front->next;

		delete temp;
		return data;
	}

	T frontItem() {
		return front->item;
	}


	bool isEmpty(){
		return front == NULL;
	}

private:
	list<T> *front;
	list<T> *rear;

};

template<typename T> struct binaryTree {
	T item;
	binaryTree<T> *left;
	binaryTree<T> *right;
};

template<typename T> stack<list<binaryTree<T>>> *d_lists ( binaryTree<T> *root ) {
	if ( root == NULL )
		return NULL;
	stack<list<binaryTree<T>> *b = new stack<list<binaryTree<T>>();
	queue<binaryTree<T>> *q = new queue<binaryTree<T>>();
	binaryTree<T> *temp; list<binaryTree<T>> *con = new list<binaryTree<T>>;
	q->enQueue ( *root );
	while ( !q->isEmpty() ) {
		int size = q->size();
		while ( size > 0 ) {
			temp = q->deQueue();
			insert( con, temp );
			if ( temp->left ) q->enQueue (*(temp->left) );
			if ( temp->right ) q->enQueue (*(temp->right) );
			size--;
		}
		b->push(*con);
		delete con;
		list<binaryTree<T>> *con = new list<binaryTree<T>>;
	}
	delete q;
	return b;
}





int main()
{

	return 0;
}