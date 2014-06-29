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

bool is_anagram ( string a, string b ) {
	int buffer[256] = {0};
	for ( int i = 0; i < a.size(); i++)
		buffer[a[i]]++;
	for ( int i = 0; i < b.size(); i++)
		buffer[b[i]]--;
	for ( int i=0; i < 256; i++)
		if ( buffer[i] != 0 )
			return false;
	return true;
}


void sort_by_anagram ( vector<string>& A) {
	if ( A.empty() || A.size() == 1 ) return;
	for ( int i = 0; i < A.size()-1; i++) {
		int q = i+1; int s_c = 0;
		for ( int j = i+1; j < A.size(); j++) {
			if ( is_anagram(A[i],A[j]) ) {
				swap(A[q], A[j]);
				q++; s_c++;
			}

		}
		i+=s_c;
	}

}

int partition_mod ( vector<string> A, int low, int high ) {
	int i = low; int p = high; int first_not_angrm= low;
	for (; i< high; i++ ) {
		if ( is_anagram(A[i], A[p]) ) {
			swap( A[i], A[first_not_angrm] );
			first_not_angrm++;
		}

	}
	swap ( A[p], A[first_not_angrm] );
	return first_not_angrm;
}

void quicksort_mod ( vector<string> A, int low, int high) {
	if ( low < high ) {
		int p = partition_mod(A,low,high);
		quicksort_mod(A,low,p-1);
		quicksort_mod(A,p+1,high);
	}

}



int main()
{
	vector<string> a;
	a.push_back("abc");
	a.push_back("dfg");
	a.push_back("cab");
	a.push_back("fgd");
	a.push_back("bca");
	a.push_back("gfd");

	quicksort_mod(a,0,5);
//	sort_by_anagram(a);

	return 0;
}