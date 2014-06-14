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

template <typename T> void deleteNode ( list<T> *d )
{
	if ( d == NULL || d->next == NULL ) return;
	list<T> *p = d->next;
	d->item = p->item;
	d->next = p->next;
	delete p;

}




int main()
{
	list<int> *myList = new list<int>; myList = NULL;
	list<int> **p= &myList;
	insert_list ( p, 10);
	insert_list ( p, 5);
	insert_list ( p, 3);
	insert_list ( p, 4);
	
	deleteNode(myList); 

	return 0;
}