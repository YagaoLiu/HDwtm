#include <string>

#include "defs.h"
#include "globals.h"

using namespace std;

inline unsigned int popcount8 ( int x )
{
	//__builtin_popcount: 32-bit
	//__builtin_popcountll: 128-bit
	//http://www.dalkescientific.com/writings/diary/archive/2011/11/02/faster_popcount_update.html
	return __builtin_popcountl( x );
}

inline static unsigned int bitcountpair(uint32_t const n)
{
	return popcount8(((n >> 1) | n) & 0x55555555ul);
}

inline static unsigned int diffcountpair(uint32_t const a, 
		uint32_t const b)
{
	return bitcountpair( a ^ b );
}

unsigned int HammingDistance ( unsigned int a, unsigned int b )
{
	unsigned int c = a ^ b;
	unsigned int hd = __builtin_popcount ( ( ( c>>1 ) | c ) & 0x55555555ul );
	return c;
}

void Index ( unsigned int q, long int size, unsigned int * M )
{
	string P_bi;
	P_bi.reserve ( m * 2 );
	for ( long int i = 0; i < m; i++ )
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
			hd = diffcountpair( i, p);
			if ( hd < HDmin )
				HDmin = hd;
		}
		M[i] = HDmin;
	}
}

