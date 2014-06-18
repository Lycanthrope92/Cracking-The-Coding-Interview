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

bool permutation ( char *a, char *b ) {
	if ( !a || !b ) return false;

	int buff[256] = {0};

	for ( int i = 0; a[i] != '\0'; i++ ) {
		if ( a[i] != ' ' )
			buff[a[i]]++;
	}

	for ( int i = 0; b[i] != '\0'; i++) {
		if ( b[i] != ' ' ) {
			if ( buff[b[i]] == 0 )
				return false;
			else
				buff[b[i]]--;
		}

	}

	for ( int i=0; i<256; i++)
		if ( buff[i] != 0 )
			return false;

	return true;
}









int main()
{
	char a[] = "omar";
	char b[] = "ar om";
	
	bool x = permutation(a,b);

	return 0;
}