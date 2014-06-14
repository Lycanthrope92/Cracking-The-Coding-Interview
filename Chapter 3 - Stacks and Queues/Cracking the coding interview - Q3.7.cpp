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

class queue {
public:
	queue(){
		front = NULL;
		rear = NULL;
	}

	void enQueue ( char x ){
		list<char> *temp = new list<char>;
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

	char deQueueAny() {
		if ( this->isEmpty() )
			return INT_MIN;
		list<char> *temp = front;
		char data = front->item;
		if ( front == rear ){
			front = NULL;
			rear = NULL;
		}
		else
			front = front->next;

		delete temp;
		return data;
	}

	char deQueueCat() {
		if ( front == NULL ) return INT_MIN;
		if ( front->item == 'c' ) return this->deQueueAny();
		list<char> *current = front->next; list<char> *prev = front;
		while ( current != NULL && current->item != 'c' ) {
			current = current->next; prev = prev->next;
		}
		if ( current == NULL ) return INT_MIN;
		if ( current->next == NULL ) rear = prev;
		prev->next = current->next;
		delete current;
		return 'c';

	}

	char deQueueDog() {
		if ( front == NULL ) return INT_MIN;
		if ( front->item == 'd' ) return this->deQueueAny();
		list<char> *current = front->next; list<char> *prev = front;
		while ( current != NULL && current->item != 'd' ) {
			current = current->next; prev = prev->next;
		}
		if ( current == NULL ) return INT_MIN;
		if ( current->next == NULL ) rear = prev;
		prev->next = current->next;
		delete current;
		return 'd';

	}

	char frontItem() {
		return front->item;
	}


	bool isEmpty(){
		return front == NULL;
	}

private:
	list<char> *front;
	list<char> *rear;

};



int main()
{
	queue *myS = new queue;
	myS->enQueue('c');
	myS->enQueue('d');
	myS->enQueue('c');
	char x = myS->deQueueDog();

	
	return 0;
}