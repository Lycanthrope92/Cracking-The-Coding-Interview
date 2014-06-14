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

template <typename T> list<T> *partition ( list<T> *(it) , T x)
{
	if ( (it) == NULL )
		return NULL;

	list<T> *p = new list<T>; p->item = (it)->item; p->next == NULL;
	list<T> *first = p;

	for ( list<T> *it = (it)->next; it != NULL; it=it->next )
	{
		list<T>* temp = new list<T>; temp->item = it->item;
		if ( it->item >= x )
		{
			temp->next = NULL;
			p->next = temp;
			p = p->next;
		}
		else
		{
			temp->next = first;
			first = temp;
		}

	}
	
	return first;

}

template <typename T> void partition2 ( list<T> **head, T x)
{
	if ( *head == NULL ) return;
	list<T> *endNode= *head;
	for (; endNode->next != NULL; endNode = endNode->next ){}
	list<T> *stopNode = endNode;
	for ( list<T> *it = *head, *it2 = NULL; it != stopNode; )
	{
		if ( it->item >= x )
		{
			list<T> *added = new list<T>;
			added->item = it->item;
			added->next = NULL;
			endNode->next = added;
			endNode = added;

			if ( it2 == NULL)
			{
				list<T> *del = it;
				it = it->next;
				delete del;
			}
			else
			{
				list<T> *del = it;
				it2->next = it->next;
				it = it->next;
				delete del;
			}
		}
		else
		{
			it2 = it;
			it = it->next;
		}


	}

}





int main()
{
	list<int> *myList = new list<int>; myList = NULL;
	list<int> **p= &myList;
	insert_list ( p, 10);
	insert_list ( p, 5);
	insert_list ( p, 3);
	insert_list ( p, 4);
	insert_list ( p, 6);
	insert_list ( p, 2);
	
	partition2(p, 5); 

	return 0;
}