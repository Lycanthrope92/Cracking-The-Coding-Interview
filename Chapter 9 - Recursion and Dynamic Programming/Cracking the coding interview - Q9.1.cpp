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

int count_ways_rec ( int n ) {
	if ( n < 0 ) return 0;
	if ( n == 0 ) return 1;
	if ( n == 1 ) return 1;
	if ( n == 2 ) return 2;
	if ( n > 2 ) 
		return ( count_ways_rec(n-1)+count_ways_rec(n-2)+count_ways_rec(n-3) );
}

int count_ways ( int n ) {
	if ( n <= 0 ) return -1;
	return count_ways_rec(n);
}







int main()
{
	int x = count_ways(4);

	return 0;
}