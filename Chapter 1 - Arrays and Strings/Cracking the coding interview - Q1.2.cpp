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

void reverse ( char *a ) {
	if ( a== NULL ) return;
	int size = strlen(a);
	int i = 0; int j = size -1;
	while ( i < size/2 && j >= (size/2) + size%2 ) {
		
		char temp = a[i];
		a[i] = a[j];
		a[j] = temp;

		i++;
		j--;
	}
	return;
}








int main()
{
	char a[] = "Omar is my name.";

	reverse(a);

	return 0;
}