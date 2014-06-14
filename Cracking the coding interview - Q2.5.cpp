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

template <typename T> list<T>* addition ( list<T> *n1, list<T> *n2 )
{
	if ( n1 == NULL && n2 == NULL ) return NULL;

	list<T> *result = new list<T>; result = NULL;
	list<T> *endNode = new list<T>; endNode = result;

	int carryin = 0; list<T> *t1 = n1; list<T> *t2 = n2;
	while ( t1 != NULL || t2 != NULL )
	{
		if ( t1 != NULL && t2 != NULL )
		{
			int temp = t1->item + t2->item + carryin;
			if ( temp >= 10 )
			{
				list<T> *p = new list<T>;
				p->item = temp % 10;
				p->next = NULL;
				if ( result == NULL )
				{
					result = p;
					endNode = result;
				}
				else
				{
					endNode->next = p;
					endNode = p;
				}

				carryin = 1;
			}
			else
			{
				list<T> *p = new list<T>;
				p->item = temp;
				p->next = NULL;
				if ( result == NULL )
				{
					result = p;
					endNode = result;
				}
				else
				{
					endNode->next = p;
					endNode = p;
				}
				carryin = 0;

			}

			t1 = t1->next;
		t2 = t2->next;
		}
		else if ( t1 != NULL && t2 == NULL )
		{
			int temp = t1->item + carryin;
			if ( temp >= 10 )
			{
				list<T> *p = new list<T>;
				p->item = temp % 10;
				p->next = NULL;
				if ( result == NULL )
				{
					result = p;
					endNode = result;
				}
				else
				{
					endNode->next = p;
					endNode = p;
				}

				carryin = 1;
			}
			else
			{
				list<T> *p = new list<T>;
				p->item = temp;
				p->next = NULL;
				if ( result == NULL )
				{
					result = p;
					endNode = result;
				}
				else
				{
					endNode->next = p;
					endNode = p;
				}
				carryin = 0;
			}

			t1 = t1->next;
		}
		else
		{
			int temp = t2->item + carryin;
			if ( temp >= 10 )
			{
				list<T> *p = new list<T>;
				p->item = temp % 10;
				p->next = NULL;
				if ( result == NULL )
				{
					result = p;
					endNode = result;
				}
				else
				{
					endNode->next = p;
					endNode = p;
				}

				carryin = 1;
			}
			else
			{
				list<T> *p = new list<T>;
				p->item = temp;
				p->next = NULL;
				if ( result == NULL )
				{
					result = p;
					endNode = result;
				}
				else
				{
					endNode->next = p;
					endNode = p;
				}
				carryin = 0;
			}

			
		t2 = t2->next;

		}

	}
		
return result;
}








		int main()
		{
			list<int> *myList = new list<int>; myList = NULL;
			list<int> **p= &myList;
			list<int> *myList2 = new list<int>; myList2 = NULL;
			list<int> **p2= &myList2;
			insert_list ( p, 1);
			insert_list ( p, 6);
			insert_list ( p, 1);
			insert_list ( p, 7);
			insert_list ( p2, 2);
			insert_list ( p2, 9);
			insert_list ( p2, 5);

			list<int> *result = addition(myList, myList2);

			return 0;
		}