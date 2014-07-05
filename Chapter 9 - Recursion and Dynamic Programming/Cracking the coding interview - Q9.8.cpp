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

int count_ways ( int n, int p ) {
	if ( n == 0 ) return 1;
	if ( n < 0 ) return 0;
	if ( p == 25 ) 
		return count_ways(n-25,25) + count_ways(n-10,10) + count_ways(n-5,5) + count_ways(n-1,1);
	else if ( p == 10 ) 
		return count_ways(n-10,10)+count_ways(n-5,5)+count_ways(n-1,1);
	else if ( p == 5 )
		return count_ways(n-5,5)+count_ways(n-1,1);
	else
		return count_ways(n-1,1);
}

int count_ways_wrapper ( int n ) {
	if ( n < 1 ) return -1;
	return count_ways (n,25);
}


int main()
{
	int x = count_ways_wrapper(11);

	return 0;
}