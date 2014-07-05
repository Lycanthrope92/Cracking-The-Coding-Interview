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

int count_paths ( int x, int y ) {
	if ( x < 0 || y < 0 ) return 0;
	else if ( x == 0 && y == 0) return 1;
	else
		return (count_paths(x-1,y)+count_paths(x,y-1));
}

int factorial ( int x ) {
	if ( x < 0 ) return -1;
	int fact = 1;
	while ( x > 0 ) {
		fact *= x;
		x--;
	}
	return fact;
}


int count_paths2 ( int x, int y) {
	if ( x < 0 || y < 0 ) return -1;
	return ( factorial(x+y)/(factorial(x)*factorial(y)) );
}

void print_paths ( int x, int y, string path ) {
	if ( x < 0 || y < 0 ) return;
	else if ( x == 0 && y == 0 ) cout << path << endl;
	else {
		string path1 = path+"R";
		string path2 = path+"D";
		print_paths ( x-1, y, path1 );
		print_paths ( x, y-1, path2 );
	}

}





int main()
{
	int x = count_paths(1,2);
	print_paths(1,2, "");

	return 0;
}