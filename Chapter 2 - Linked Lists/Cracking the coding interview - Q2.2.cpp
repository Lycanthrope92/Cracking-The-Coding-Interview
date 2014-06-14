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

template <typename T> list<T> *findkthtolast ( list<T> *head, int k)
{
	if ( head == NULL || k < 1 )
		return NULL;

	list<T> *p = head; int count = 1;
	while ( p != NULL && count < k )
	{
		count++; p = p ->next;
	}

	if ( p == NULL )
		return NULL;
	else
	{
		list<T> *q = head;
		while ( p->next != NULL )
		{
			q = q->next;
			p = p->next;
		}
		return q;

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
	
	list<int> *k = findkthtolast(myList, 1); 

	return 0;
}