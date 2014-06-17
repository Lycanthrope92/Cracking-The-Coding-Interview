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

bool is_unique ( char *a ) {
	if ( a == NULL ) return false;
	int con[256] = {0};
	int size = strlen(a);
	for ( int i = 0; i< size; i++) {
		if ( con[a[i]] == 1 )
			return false;
		else
			con[a[i]]++;
	}

	return true;
}

bool is_unique2 ( char *a ) {
	if ( a== NULL ) return false;
	int size = strlen(a);
	for ( int i = 0; i < size - 1; i++)
		for ( int j = i+1; j < size; j++) {
			if ( a[i] == a[j] )
				return false;
		}

	return true;
}







int main()
{
	char *a = "abcdb";

	bool x = is_unique(a);
	x = is_unique2(a);

	return 0;
}