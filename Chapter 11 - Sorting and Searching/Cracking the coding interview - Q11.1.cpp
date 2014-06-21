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

void merge1 ( int A[], int n, int a, int B[], int b ) {
	if ( n != (a+b) || a < 1 || b < 1 || n < 1 ) return;
	int it1 = a-1;
	int it2 = n-1;
	while ( it1>= 0) 
		A[it2--] = A[it1--];
	int i = it2+1; int j = 0; int q = 0;
	while ( i < n && j < b ) {
		if ( A[i] <= B[j] )
			A[q++] = A[i++];
		else
			A[q++] = B[j++];
	}

	while ( i < n ) A[q++] = A[i++];
	while (j < b) A[q++] = B[j++];
}

void merge2 ( int A[], int n, int a, int B[], int b ) {
	if ( n != (a+b) || a < 1 || b < 1 || n < 1 ) return;
	
	int i = a-1; int j = b-1; int q = n-1;
	while ( j >= 0 ) {
		if ( A[i] > B[j] )
			A[q--] = A[i--];
		else
			A[q--] = B[j--];
	}

}






int main()
{
	int a[] = { 1, 8, 9, 10, 0, 0, 0};
	int b[] = { 2, 4, 6};

	merge2(a, 7, 4, b, 3);

	return 0;
}