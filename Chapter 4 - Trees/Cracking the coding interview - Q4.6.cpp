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
	binaryTree<T> *parent;
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

template<typename T> binaryTree<T> *successor ( binaryTree<T> *root, binaryTree<T> *node ) {
	if ( root == NULL || node == NULL ) return NULL;
	if ( root->right ) return findMin (root->right);
	if ( node->parent->item > node->item ) return node->parent;
	while ( root ) {
		if ( root->item > node->item )
			return root;
		else
			root = root->right;
	}
	return NULL;

}





int main()
{
	binaryTree<int> *tree = new binaryTree<int>;
	tree->item = 20;
	binaryTree<int> *temp = new binaryTree<int>;
	temp->item = 10; 
	binaryTree<int> *temp2 = new binaryTree<int>;
	temp2->item = 30;
	binaryTree<int> *temp3 = new binaryTree<int>;
	temp3->item = 25;
	temp->left = NULL; temp->right = temp3;
	temp2->left = NULL; temp2->right = NULL;
	temp3->left = NULL; temp3->right = NULL;
	tree->left = temp;
	tree->right = temp2;
	
	bool check = checkIfBST(tree);

	return 0;
}