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

int binary_search_mod ( const vector<string>& a, string x ) {
	if ( a.empty() || x.empty() ) return -1;
	int low = 0; int high = a.size()-1;
	while ( low <= high ) {
		int mid = low + (high-low)/2;
		if ( a[mid].empty() ) {
			bool changed = false;
			for ( int i = 1; !changed; i++ ) {
				if ( mid+i<= high && !a[mid+i].empty() ) {mid = mid+i; changed = true;}
				else if ( mid-i >= low && !a[mid-i].empty() ) {mid=mid-i; changed = true;}
				else if ( mid-i < low && mid+i > high ) return -1;
			}

		}

		if ( x == a[mid] ) return mid;
		else if ( x > a[mid] ) low = mid+1;
		else high = mid - 1;

	}

	return -1;
}




int main()
{
	vector<string> a;
	a.push_back("");
	a.push_back("");
	a.push_back("a");
	a.push_back("");
	a.push_back("");
	a.push_back("b");

	int x = binary_search_mod(a,"");



	return 0;
}