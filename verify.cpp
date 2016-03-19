#include <vector>

#include "defs.h"
#include "globals.h"

using namespace std;

bool verify ( unsigned int a )
{
	double p = 1;
	unsigned int hd = 0;
	for ( unsigned int i = 0; i < m; i++, a++ )
	{
		int l = alphabet.find ( pattern[i] );
		if ( p * text[a][l] >= z )
		{
			p *= text[a][l];
		}
		else
		{
			hd += 1;
			if ( hd > k )
				return false;
		}
	}
	return true;
}
