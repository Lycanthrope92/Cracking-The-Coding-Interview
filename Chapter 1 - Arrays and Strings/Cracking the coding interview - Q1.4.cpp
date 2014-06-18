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

void modify ( char *a ) {
	if ( !a ) return;
	int size = strlen(a);
	int i = size-1;
	int r = size-1;
	while ( a[i] == ' ') {
		i--;
	}

	while ( i >= 0 ) {
		if ( a[i] == ' ' ) {
			a[r] = '0'; r--;
			a[r] = '2'; r--;
			a[r] = '%'; r--;
		} else {
			a[r] = a[i];
			r--;
		}

		i--;
	}


}










int main()
{
	char a[] = "Mr John Smith    ";
	
	modify(a);

	return 0;
}