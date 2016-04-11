#include <vector>

#include <ctime>
#include <iostream>

#include "defs.h"
#include "globals.h"

using namespace std;

extern string text_heavy;

int partition(vector < double >  &input, int p, int r)
{
	double pivot = input[r];

	while ( p < r )
	{
		while ( input[p] < pivot )
			p++;

		while ( input[r] > pivot )
			r--;

		if ( input[p] == input[r] )
			p++;
		else if ( p < r ) {
			double tmp = input[p];
			input[p] = input[r];
			input[r] = tmp;
		}
	}

	return r;
}

double quick_select( vector < double > &input, int p, int r, int kk)
{
	if ( p == r ) return input[p];
	int j = partition(input, p, r);
	int length = j - p + 1;
	if ( length == kk ) return input[j];
	else if ( kk < length ) return quick_select(input, p, j - 1, kk);
	else  return quick_select(input, j + 1, r, kk - length);
}

bool verify ( unsigned int a )
{
	vector < double > A;
	A.reserve ( m );
	vector <clock_t> ss,ff;
	int k1 = k;
	double p = 1;
	string u ( pattern );
	for ( unsigned int i = 0; i < m; i++, a++ )
	{
		if ( u[i] != text_heavy[a] )
		{
			int lu = alphabet.find ( u[i] );
			int lv = alphabet.find ( text_heavy[a] );
			if ( text[a][lu] == 0 )
			{
				p *= text[a][lv];
				k1 --;
				if ( k1 < 0 )
				{
					return false;
				}
			}
			else
			{
				p *= text[a][lu];
				double dpi = text[a][lv] / text[a][lu];
				A.push_back ( dpi );
			}
		}
	}
	if ( A.size() > k1 )
	{
		double k_p = quick_select ( A, 0, A.size()-1, k1 );
		for ( unsigned int i = 0, j = 0; i < A.size(), j < k1; i++ )
		{
			if ( A[i] >= k_p )
			{
				p *= A[i];
				j ++;
			}
		}
	}
	else
	{
		for ( unsigned int i = 0; i < A.size(); i++ )
		{
			p *= A[i];
		}
	}

	if ( p >= z )
		return true;
	else
		return false;
}
