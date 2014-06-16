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


template<typename T> struct binaryTree {
	T item;
	binaryTree<T> *left;
	binaryTree<T> *right;
};

template<typename T> bool isSub ( binaryTree<T> *T1, binaryTree<T> *T2 ) {
	if ( T1 != NULL && T2 != NULL )
		if ( T1->item == T2->item )
			return ( isSub(T1->left, T2->left) && isSub(T1->right, T2->right) );
		else
			return false;
	else if ( T1 == NULL && T2 == NULL )
		return true;
	else
		return false;
}

template<typename T> bool check ( binaryTree<T> *T1, binaryTree<T> *T2 ) {
	if ( T1 == NULL || T2 == NULL )
		return false;
	else if ( isSub (T1, T2) )
		return true;
	else
		return ( check(T1->left,T2) || check(T1->right, T2) );
}





int main()
{

	return 0;
}