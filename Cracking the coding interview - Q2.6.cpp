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


template <typename T> void insert_list ( list<T> **l, T x)
{
	list<T>* p = new list<T>;
	p->item = x;
	p->next = *l;
	*l = p;
}

template <typename T> list<T> *loop_begining ( list<T> *head )
{
	if ( head == NULL ) return NULL;

	list<*T> **p = new list<T>;
	p->item = head;
	p->next = NULL;
	for ( list<T>* it = head->next;; it = it -> next)
	{
		for ( list<*T> *it2= p; it2 != NULL; it2 = it2 -> next)
		{
			if ( it2->item == it )
			{
				return it;
			}

		}
		list<*T> *temp = new list<*T>;
		temp->item = it;
		temp->next = p;
		p = temp;

	}

	return NULL;

}

template<typename T> list<T> *loop_begining2 (list<T> *head )
{
	if ( head == NULL ) return NULL;

	list<T> *first = head; bool notFound = true;
	list<T> *second = head->next;
	while ( notFound )
	{
		list<T> *it = first; list<T> *it2 = second;
		while ( it != it2 )
		{
			it->next; it2->next;
			if ( it == first )
				break;
		}
		if ( it == it2 ) return it;
		second = second->next;
	}

	return NULL;
}

template <typename T> list<T> *loop_begining3 (list<T> *head)
{
	if ( head == NULL ) return NULL;

	list<T>* it2 = head->next;
	list<T>* temp = head;
	int count = 1;
	while ( temp != it2 )
	{
		temp = it2;
		for ( int i = count; i >= 0; i--)
		{
			it2 = it2->next;
		}
		count++;
	}
	list<T> *it1 = head; it2 = head;
	for ( int i = count; i > 0; i--)
		it2 = it2->next;
	while ( it1 != it2 )
	{
		it1 = it1 -> next;
		it2 = it2->next;
	}

	return it1;
}







int main()
{
	list<int> *myList = new list<int>; myList = NULL;
	list<int> **p= &myList;

	insert_list ( p, 1);
	insert_list ( p, 6);
	insert_list ( p, 1);
	insert_list ( p, 7);
	insert_list ( p, 2);
	list<int> *it = myList;
	for ( ; it->next != NULL; it = it->next )
	{
	}

	it->next = myList->next->next->next->next;

	list<int> *b = loop_begining3(myList);

	return 0;
}