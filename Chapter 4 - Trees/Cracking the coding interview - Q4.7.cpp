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

template<typename T> bool foundNode ( binaryTree<T> *root, binaryTree<T> *node ) {
	if ( root )
		if ( root == node ) {
			return true;
		}
		else {
			return ( foundNode (root->left, node) || foundNode (root->right, node) );
		}
	else
		return false;

}

template<typename T> binaryTree<T> *ancestor ( binaryTree<T> *root, binaryTree<T> *node1, binaryTree<T> *node2 ) {
	if ( root == NULL ) return NULL;
	bool found1L = foundNode ( root->left, node1 );
	bool found2L = foundNode ( root->left, node2 );
	bool found1R = foundNode ( root->right, node1 );
	bool found2R = foundNode ( root->right, node2 );

	if ( (found1L&&found2R) || (found2L&&found1R) || root == node1 || root == node2 ) {
		return root;
	}
	else if ( found1L && found2L )
		return ancestor(root->left, node1, node2);
	else if ( found1R && found2R )
		return ancestor(root->right, node1, node2);
	else
		return null;

}





int main()
{

	return 0;
}