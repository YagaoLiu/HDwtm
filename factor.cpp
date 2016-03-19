#include <vector>
#include <string>

#include <iostream>

#include "defs.h"
#include "globals.h"

using namespace std;

void factor ( int a, int q, string x, double p, vector < string > * list )
{
	if ( a == q )
	{
		list->push_back ( x );
	}
	else
	{
		for ( int i = 0; i < sigma; i++ )
		{
			if ( p * text[a][i] >= z )
			{
				string x2 = x;
				double p2 = p;
				p2 *= text[a][i];
				x2.push_back ( alphabet[i] );
				factor ( a+1, q, x2, p2, list );
			}
		}

	}
}
