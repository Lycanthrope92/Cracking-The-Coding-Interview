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

template<typename T> getHeight ( binaryTree<T> *root) {
	if ( root )
		return max(getHeight(root->left), getHeight(root->right)) + 1;
	else
		return 0;
}

template<typename T> bool isBlanced (binaryTree<T> *root) {
	if ( root ) {
		if ( abs(getHeight(root->left)-getHeight(root->right) > 1 )
			return false;
		else
			return ( isBalnced(root->left) && isBlanced(root->right) );
	}
	else
		return true;

}




int main()
{

	return 0;
}