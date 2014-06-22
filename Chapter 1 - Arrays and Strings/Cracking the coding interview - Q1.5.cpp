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

char* compress (char* a) {
	if ( a == NULL ) return NULL;
	int size = strlen(a);
	if ( size == 1|| size == 2)
		return a;
	int unique = 1;
	for (int i = 0; i < size-1; i++)
		if ( a[i] != a[i+1] )
			unique++;
	if ( 2*unique >= size )
		return a;

	char* b = new char[2*unique+1];
	int j = 0; int count = 1; int i;
	for ( i = 0; i < size; i++) {
		if (a[i] ==a[i+1] )
			count++;
		else {
			b[j] = a[i]; j++; char *c = new char; itoa(count,c,10);
			b[j] = *c; j++;
			count = 1;
			
		}

	}
	b[j] = a[i]; j++; char *c = new char; itoa(count,c,10);
			b[j] = *c; j++;
	b[j] = '\0';

	return b;

}











int main()
{
	char a[] = "aabccccca";
	
	char *b = compress(a);

	return 0;
}