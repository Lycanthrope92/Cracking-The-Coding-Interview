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

int binary_search ( int a[], int x, int start, int end ) {
	int mid = (start+end)/2;
	if ( x > a[mid] )
		return binary_search(a,x,mid+1,end);
	else if ( x < a[mid] )
		return binary_search(a,x,start,mid-1);
	else
		return mid;
}


int find_element ( int a[], int n, int x ) {
	if ( a== NULL || n < 1 ) return -1;
	if ( n == 1 && a[0] != x ) return -1;
	int b_p = 0;
	for ( int i = 0; i < n-1; i++ )
		if ( a[i+1] < a[i] ) {
			b_p = i+1;
			break;
		}

	if ( x > a[0] )
		return binary_search(a, x, 0, b_p-1 );
	else if ( x < a[0] )
		return binary_search ( a, x, b_p, n-1);
	else
		return 0;

}




int main()
{
	int a[] = { 15, 16, 19,20,25,1,2,3,4,5,7,10,14};

	int i = find_element(a,12,25);

	return 0;
}