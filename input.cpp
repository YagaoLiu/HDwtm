#include <iostream>
#include <string>
#include <cstring>
#include <getopt.h>

#include "defs.h"

static struct option long_options[] =
{
	{ "pattern",			required_argument,	NULL,	'p' },
	{ "text",				required_argument,	NULL,	't' },
	{ "output",				required_argument,	NULL,	'o' },
	{ "threshold",			required_argument,	NULL,	'z'	},
	{ "mismatch",			required_argument,	NULL,	'k' },
	{ "q-gramtime",			required_argument,	NULL,	'q' },
	{ "help",				0,					NULL,	'h' },
};

int decode_switches ( int argc, char * argv[], struct TSwitch * sw )
{
	int opt;
	char *ep;
	double val;
	int args;

	/* initialisation */
	sw -> z	=	1;
	sw -> k	=	1;					

	args = 0;

	while ( ( opt = getopt_long ( argc, argv, "p:t:o:z:k:q:h", long_options, NULL ) ) != -1 )
	{
		switch ( opt )
		{
			case 'p':
				sw -> pattern_file_name = optarg;
				args ++;
				break;
			case 't':
				sw -> text_file_name = optarg;
				args ++;
				break;
			case 'o':
				sw -> output_file_name = optarg;
				args ++;
				break;
			case 'z':
				val = strtod ( optarg, &ep );
				if ( optarg == ep )
				{
					return 0;
				}
				sw -> z = val;
				args ++;
				break;
			case 'k':
				val = strtol ( optarg, &ep, 10 );
				if ( optarg == ep )
				{
					return 0;
				}
				sw -> k = val;
				args ++;
				break;
			case 'q':
				val = strtol ( optarg, &ep, 10 );
				if ( optarg == ep )
				{
					return 0;
				}
				sw -> times = val;
				args ++;
				break;
			case 'h':
				return 0;
		}
	}

	if ( args < 5 )
	{
		usage();
		exit ( 1 );
	}
	else
		return ( optind );
}

void usage ( void )
{
	cout << "Usage: HDwpm <options>\n";
	cout << "Standard (Mandatory):\n";
	cout << "	-p, --pattern\t<str>\tFilename for Pattern.\n";
	cout << "	-t, --text\t<str>\tFilename for Text.\n";
	cout << "	-o, --output\t<str>\tFilename for output.\n";
	cout << "	-z, --threshold\t<dbl>\tcumulative weight threshold.\n";
	cout << "	-k, --mismatch\t<int>\tHamming distance.\n";
}






