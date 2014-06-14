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

template < typename T> bool isPalindrome (list<T>* head )
{
	if ( head == NULL ) return false;

	list<T>* reverse = new list<T>;
	reverse = NULL;
	for ( list<T> *it = head; it != NULL; it =it->next )
	{
		if ( it ->item != ' ' )
		{
			list<T> *p = new list<T>;
			p->item = tolower(it->item);
			p->next = reverse;
			reverse = p;
		}

	}

	list<T> *it1 = head; list<T> *it2 = reverse;
	bool isPalindromeCondition = true;

	while ( isPalindromeCondition && it1 != NULL && it2 != NULL )
	{
		if ( tolower(it1->item) != it2->item && it1->item != ' ')
			isPalindromeCondition = false;
		else if ( it1->item == ' ' )
			it1 = it1->next;
		else
		{
			it1 = it1 ->next;
			it2 = it2->next;
		}

	}

	return isPalindromeCondition;
}







int main()
{
	list<char> *myList = new list<char>; myList = NULL;
	list<char> **p= &myList;

	insert_list ( p, 'a');
	insert_list ( p, 'b');
	insert_list ( p, 'u');
	insert_list ( p, 't');
	insert_list ( p, ' ');
	insert_list ( p, 't');
	insert_list ( p, 'u');
	insert_list ( p, 'b');
	insert_list ( p, ' ');
	insert_list ( p, 'A');
	/*insert_list ( p, 2);
	list<int> *it = myList;
	for ( ; it->next != NULL; it = it->next )
	{
	}

	it->next = myList->next->next->next->next;*/

	bool check = isPalindrome (myList);

	return 0;
}