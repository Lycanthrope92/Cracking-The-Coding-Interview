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

void print_all_subs ( int a[], int n, string sub, int zero ) {
	for ( int i = 0; i < n; i++)
		if ( sub[i] == '1' )
			cout << a[i] << ' ';
	cout << endl;

	if ( zero < n - 1 ) {
		int new_zero = zero + 1;
		int count = n - 1 - zero;
		while ( count > 0 ) {
			string new_sub = sub;
			new_sub[new_zero] = '0';
			print_all_subs ( a, n, new_sub, new_zero );
			new_zero++;
			count--;
		}

	}

}

void print_subsets_wrapper ( int a[], int n ) {
	if ( a == NULL ) return;
	string sub;
	for ( int i = 0; i < n; i++ )
		sub.push_back('1');
	print_all_subs( a, n, sub, -1);
}


int main()
{
	int a[3] = {1,2,3};
	print_subsets_wrapper(a, 3);

	return 0;
}