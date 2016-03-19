#include <string>
#include <vector>
#include <cmath>
#include <ctime>

#include <iostream>

#include "defs.h"
#include "globals.h"

using namespace std;

void match ( vector < unsigned int > * Occ )
{
	unsigned int i, j, l;
	unsigned int q = 8;

	clock_t start, finish;

	unsigned int index_size = ( unsigned int ) pow ( sigma, q );
	unsigned int * index = new unsigned int [index_size];

	start = clock();
	Index ( q, index_size, index );
	finish = clock();

	cout << "Index time:" << ( ( double ) finish - start ) / CLOCKS_PER_SEC << endl;

	i = 0;
	j = m - q;
	while ( i < n - m + 1 )
	{
		string qstr;
		unsigned int hd = q;
		double p = 1;
		vector < string > qlist;

		factor ( j, j+q, qstr, p, &qlist );
	
		for ( l = 0; l < qlist.size(); l ++ )
		{
			unsigned int id = Str2Num ( qlist[l] );
			hd = min ( hd, index[id] );
		}
		if ( hd <= k )
		{
			if ( verify ( i ) )
			{
				Occ->push_back ( i );
			}
			i += 1;
			j += 1;
		}
		else
		{
			/* skip */
			i += m - q;
			j += m - q;
		}

	}
}
