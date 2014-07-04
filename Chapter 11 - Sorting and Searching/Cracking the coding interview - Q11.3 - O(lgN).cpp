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

int find_cycle_start ( int a[], int n ) {
	if ( a == NULL ) return -1;
	int low = 0; int high = n-1;
	while ( low < high ) {
		int mid = low + (( high-low) >> 1);
		if ( a[mid] > a[high] )
			low = mid+1;
		else
			high = mid;
	}
	return low;
}

int find_k_in_cyclic_array ( int a[], int n, int k ) {
	if ( a == NULL ) return -1;
	int c_s = find_cycle_start ( a, n);
	int low = 0; int high = n-1;
	while ( low <= high ) {
		int mid = low + ((high-low) >> 1);
		if ( k == a[(mid+c_s)%n] ) return ((mid+c_s)%n);
		else if ( k > a[(mid+c_s)%n] ) low = mid+1;
		else high = mid - 1;
	}
	return -1;
}







int main()
{
	int a[] = {5,6,7,8,1,2,3,4};

	int x = find_k_in_cyclic_array(a, 8, 3);

	return 0;
}