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

template<typename T> binaryTree<T> *find ( binaryTree<T> *root, T x ) {
	while ( root != NULL ) {
		if ( x == root->item ) return root;
		else if ( x > root->item ) root = root->right;
		else root = root->left;
	}
	return NULL;
}

template<typename T> binaryTree<T> *findMin ( binaryTree<T> *root ) {
	if ( root == NULL ) return NULL;
	while ( root->left != NULL ) root = root->left;
	return root;
}

template<typename T> binaryTree<T> *findMax ( binaryTree<T> *root ) {
	if ( root == NULL ) return NULL;
	while ( root->right != NULL ) root = root->right;
	return root;
}

template<typename T> void Insert ( binaryTree<T> **root, T x ) {
	binaryTree<T> *current = *root;
	if ( current == NULL ) {
		binaryTree<T> *temp = new binaryTree<T>;
		temp->item = x;
		temp->left = temp->right = NULL;
		current = temp;
		*root = current;
	}

	while ( current != NULL ) {
		if ( x == current->item ) return;
		else if ( x > current->item ) current = current->right;
		else current = current->left;
	}
	binaryTree<T> *temp = new binaryTree<T>;
	temp->item = x;
	temp->left = temp->right = NULL;
	current = temp;
	return;
}

template<typename T> void Delete ( binaryTree<T> **root, T x ) {
	binaryTree<T>* deleteNode = find(*root, x);
	if ( deleteNode == NULL ) return;
	if ( deleteNode->left && deleteNode->right ) {
		binaryTree<T> *successor = findMin ( deleteNode->right );
		deleteNode->item = successor->item;
		binaryTree<T> *temp = successor;
		if ( successor->right ) successor = successor->right;
		else successor = NULL;
		delete temp;
	}
	else {
		binaryTree<T> *temp = deleteNode;
		if ( deleteNode->left ) deleteNode = deleteNode->left;
		else deleteNode = deleteNode->right;
		delete temp;
	}

	return;
}

template<typename T> binaryTree<T> *minhTree ( T* a, int size ) {
	if ( size < 1 ) return NULL;
	int index = size/2;
	binaryTree<T> *root = new binaryTree<T>;
	root->item = a[index];
	root->left = minhTree ( a, size/2);
	root->right = minhTree ( a+index+1, size/2 - 1 + size%2 );
	return root;
}




int main()
{
	int *a = new int[7];
	for ( int i = 0; i < 7; i++ ) a[i] = i+1;

	binaryTree<int> *tree = minhTree(a, 7);

	return 0;
}