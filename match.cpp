#include <string>
#include <vector>
#include <cmath>
#include <ctime>

#include <iostream>

#include "defs.h"
#include "globals.h"

using namespace std;

string text_heavy;

int heavyletter ( int a )
{
	int letter = 0;
	for ( int i = 1; i < sigma; i++ )
	{
		if ( text[a][i] > text[a][letter] )
			letter = i;
	}
	return letter;
}

double match ( vector < unsigned int > * Occ )
{
	unsigned int i, j, l, t;
	unsigned int q = log(m)/log(2);
	unsigned int vt = 0;

	clock_t start, finish;

	long int index_size = ( unsigned int ) pow ( sigma, q );
	unsigned int * index = new unsigned int [index_size];

	text_heavy.resize ( n );
	for ( i = 0; i < n; i++ )
		text_heavy[i] = alphabet[ heavyletter(i) ];
	

	start = clock();
	Index ( q, index_size, index );
	finish = clock();

	double itime = ( ( double ) finish - start ) / CLOCKS_PER_SEC;
	cout << "Index time:" << itime << endl;

//	times = ceil ( k / q + 1 );

	i = 0;
	while ( i < n - m + 1 )
	{
		unsigned int hd = 0;
		for ( t = 0; t < times; t++ )
		{
			unsigned int hd0 = q;
			j = i + m - q - t * q;
			string qstr;
			double p = 1;
			vector < string > qlist;
			factor ( j, j+q, qstr, p, &qlist );
			for ( l = 0; l < qlist.size(); l ++ )
			{
				int id = stoi ( qlist[l], 0, 4 );
				hd0 = min ( hd0, index[id] );
			}
			qlist.clear();
			vector < string > ().swap ( qlist );
			hd += hd0;
			if ( hd > k ) break;
		}
		if ( hd <= k )
		{
			vt ++;
			if ( verify ( i ) )
			{
				Occ->push_back ( i );
			}
			i += 1;
		}
		else
		{
			/* skip */
			i = j + 1;
		}

	}
	cout << "verify times:" << vt << endl;
	return itime;
}
