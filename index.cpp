#include <string>

#include "defs.h"
#include "globals.h"

using namespace std;
/*
unsigned int HammingDistance ( string x, string y )
{
	unsigned int hd = 0;
	for ( unsigned int i = 0; i < x.size(); i++ )
	{
		if ( x[i] != y[i] )
			hd ++;
	}
	return hd;
}
*/

unsigned int HammingDistance ( unsigned int a, unsigned int b )
{
	unsigned int c = a ^ b;
	unsigned int hd = __builtin_popcount ( ( ( c>>1 ) | c ) & 0x55555555ul );
	return c;
}

void Index ( unsigned int q, unsigned int size, unsigned int * M )
{
	string P_bi;
	P_bi.reserve ( m * 2 );
	for ( unsigned int i = 0; i < m; i++ )
	{
		int l = alphabet.find( pattern[i] );
		switch ( l )
		{
			case 0:
				P_bi.push_back('0');
				P_bi.push_back('0');
				break;
			case 1:
				P_bi.push_back('0');
				P_bi.push_back('1');
				break;
			case 2:
				P_bi.push_back('1');
				P_bi.push_back('0');
				break;
			case 3:
				P_bi.push_back('1');
				P_bi.push_back('1');
				break;
		}
	}
	for ( unsigned int i = 0; i < size; i++ )
	{
//		string Q = Num2Str ( i, q );
		unsigned int HDmin = q;
		unsigned int hd = 0;
		for ( unsigned int j = 0; j < m - q + 1; j++ )
		{
			string P ( P_bi, j*2, q*2 );
			unsigned int p = stoi( P, 0, 2 );
			hd = HammingDistance ( i, p );
			if ( hd < HDmin )
				HDmin = hd;
		}
		M[i] = HDmin;
	}
}

