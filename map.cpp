#include <string>

#include "defs.h"
#include "globals.h"

using namespace std;

string Num2Str ( unsigned int id, unsigned int length )
{
	string x;
	x.resize ( length );
	for ( int i = length - 1; i >= 0; i-- )
	{
		x[i] = alphabet[ id % sigma ];
		id /= sigma;
	}
	return x;
}

unsigned int Str2Num ( string x )
{
	unsigned int id = 0;
	for ( unsigned int i = 0; i < x.size(); i++ )
	{
		id = id * sigma + alphabet.find ( x[i] );
	}

	return id;
}

