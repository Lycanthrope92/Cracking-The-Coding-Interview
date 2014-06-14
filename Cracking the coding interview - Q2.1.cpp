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

template <typename DATA_TYPE> struct list {
	DATA_TYPE item;
	list<DATA_TYPE> *next;
};

	
template <typename DATA_TYPE> void insert_list ( list<DATA_TYPE> **l, DATA_TYPE x)
{
	list<DATA_TYPE>* p = new list<DATA_TYPE>;
	p->item = x;
	p->next = *l;
	*l = p;
}

template <typename DATA_TYPE> void remove_duplicates ( list<DATA_TYPE> *l )
{
	if ( l == NULL )
		return;

	list<DATA_TYPE> *p = l;
	while ( p )
	{
		list<DATA_TYPE> *pred, *q;
		q = p->next; pred = p;
		while ( q )
		{
			if ( p->item == q->item )
			{
				list<DATA_TYPE> *t = q;
				pred->next = q->next;
				q = pred->next;
				delete t;
			}
			else
			{
				pred = q;
				q = q->next;
			}

		}
		
		p = p->next;
	}


}


int main()
{
	list<int> *myList = new list<int>; myList = NULL;
	list<int> **p= &myList;
	insert_list ( p, 10);
	insert_list ( p, 10);
	insert_list ( p, 10);

	remove_duplicates (myList);

	return 0;
}