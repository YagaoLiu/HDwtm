#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cmath>

#include "defs.h"

using namespace std;

string		alphabet = DNA;
int			sigma	 = 4;
string		pattern;
double **	text;
double		z;
unsigned int	k;
unsigned int	m;
unsigned int	n;

int main ( int argc, char ** argv )
{
	TSwitch sw;
	string pattern_file;
	string text_file;
	string output_file;
	unsigned int num_Occ;
	vector<unsigned int> Occ;
	ofstream result;
	double kpc;

	clock_t start, finish;

	/* Decodes the arguments */
	int	AR = decode_switches ( argc, argv, &sw );

	/* Check the arguments */
	if ( AR < 9 )
	{
		usage();
		return 1;
	}
	else
	{
		if ( sw.pattern_file_name.size() == 0 )
		{
			cout << "Error: No Pattern input!\n";
			return 0;
		}
		else
		{
			pattern_file = sw.pattern_file_name;
		}

		if ( sw.text_file_name.size() == 0 )
		{
			cout << "Error: No Text input!\n";
			return 0;
		}
		else
		{
			text_file = sw.text_file_name;
		}

		if ( sw.output_file_name.size() == 0 )
		{
			cout << "Error: No output file!\n";
		}
		else
		{
			output_file = sw.output_file_name;
		}

		if ( sw.z > 0 )
		{
			z = 1 / sw.z;
		}
		else
		{
			cout << "Error: z must be a positive integer!\n";
		}

		if ( sw.k >= 0 )
		{
			k = sw.k ;
		}
		else
		{
			cout << "Error: k must be a non-negative integer!\n";
		}
	}	
	/* read input */
	if ( read ( pattern_file, 'p' ) < 0 )
	{
		return 0;
	}
	if ( read ( text_file, 't' ) < 0 )
	{
		return 0;
	}

	start = clock();

	double itime =	match ( &Occ );

	finish = clock();

	double elapsed_time = ( ( double ) finish - start ) / CLOCKS_PER_SEC;

	num_Occ = Occ.size();

	cout << "Pattern length:" << m << "\tText length:"<< n << '\n';
	cout << "Number of Occurrences:" << num_Occ << '\n';
	cout << "Elapsed time:" << elapsed_time << "s\n";
#if 0
	result.open ( output_file );
	if ( num_Occ == 0 )
	{
		result << "No occurrences is found.\n";
	}
	else
	{
		result << "Position of Occurrences:\n";
		for ( int i = 0; i < num_Occ; i++ )
			result << Occ[i] << '\n';
	}
#endif

	result.open ( "k-wsm.dat", ios::app );
	result << m << '\t' << elapsed_time << '\t' << itime << '\n';
	result.close();

	return 1;
}

