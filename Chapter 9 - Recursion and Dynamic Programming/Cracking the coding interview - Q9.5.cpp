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

void print_recurse ( string input, string copy ) {
	if ( input.size() == 2 ) {
		cout << copy << input[0] << input[1] << endl;
		cout << copy << input[1] << input[0] << endl;
	} else {
		for ( int i = 0; i < input.size(); i++ ) {
			string new_copy = copy; string new_input = "";
			new_copy+=input[i];
			for ( int j = 0; j < input.size(); j++ ) 
				if ( j != i ) new_input += input[j];

			print_recurse(new_input, new_copy);

		}

	}


}


void print_recurse_ith_arrangement ( string input, string copy, int& count, int k ) {
	if ( input.size() == 2 ) {
		if ( count == k )
		{cout << copy << input[0] << input[1] << endl; count++;return;}
		else
			count++;
		if (count == k )
		{cout << copy << input[1] << input[0] << endl;  count++; return;}
		else
			count++;
	} else {
		for ( int i = 0; i < input.size(); i++ ) {
			string new_copy = copy; string new_input = "";
			new_copy+=input[i];
			for ( int j = 0; j < input.size(); j++ ) 
				if ( j != i ) new_input += input[j];

			print_recurse_ith_arrangement(new_input, new_copy, count, k);

		}

	}


}

void print_all_permutations ( string input ) {
	if ( input.empty() ) return;
	if ( input.size() == 1) { cout << input; return; }
	print_recurse(input, "" );
}




int main()
{
	int count = 0;
	print_recurse_ith_arrangement("ATEHZ", "", count, 119);

	return 0;
}