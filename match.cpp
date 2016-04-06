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
	unsigned int i, j, l, t;
	unsigned int q = 10;
	unsigned int vt = 0;

	clock_t start, finish;

	long int index_size = ( unsigned int ) pow ( sigma, q );
	unsigned int * index = new unsigned int [index_size];

	start = clock();
	Index ( q, index_size, index );
	finish = clock();

	int i0,i1,i2,i3,i4,i5,i6,i7,i8;
	i0 = i1 = i2 = i3 = i4 = i5 = i6 = i7 = i8 = 0;

	for ( i = 0; i < index_size; i++ )
	{
		switch ( index[i] )
		{
			case 0:
				i0++;
				break;
			case 1:
				i1++;
				break;
			case 2:
				i2++;
				break;
			case 3:
				i3++;
				break;
			case 4:
				i4++;
				break;
			case 5:
				i5++;
				break;
			case 6:
				i6++;
				break;
			case 7:
				i7++;
				break;
			case 8:
				i8++;
				break;
		}
	}
	
	cout << "Index time:" << ( ( double ) finish - start ) / CLOCKS_PER_SEC << endl;
	cout << "Index:\n" << "0:" << i0 << "\t1:" << i1 << "\t2:" << i2 << "\n3:" << i3 << "\t4:" << i4 <<"\t5:" << i5 << "\n6:" << i6 << "\t7:" << i7 << "\t8:" << i8 << endl;

	i = 0;
	while ( i < n - m + 1 )
	{
		unsigned int hd;
		for ( t = 0; t < 1; t++ )
		{
			hd = q;
			j = i + m - q - t;
			string qstr;
			double p = 1;
			vector < string > qlist;
			factor ( j, j+q, qstr, p, &qlist );
			for ( l = 0; l < qlist.size(); l ++ )
			{
				int id = stoi ( qlist[l], 0, 4 );
				hd = min ( hd, index[id] );
			}
			qlist.clear();
			vector < string > ().swap ( qlist );
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
}
