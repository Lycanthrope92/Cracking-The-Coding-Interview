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

template<typename T> void print_path ( binaryTree<T> *root, int x, string out ) {
	if ( root == NULL ) return;
	if ( root->item == x ) cout << out << x << endl;
	x -= root->item; out += to_string(root->item);
	print_path (root->left, x, out );
	print_path (root->right, x, out);
}

template<typename T> void traverse ( binaryTree<T> *root, int x ) {
	if ( root == NULL ) return;
	print_path ( root, x, "" );
	traverse ( root->left, x);
	traverse ( root->right, x);
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
	
	traverse(tree, 50);

	return 0;
}