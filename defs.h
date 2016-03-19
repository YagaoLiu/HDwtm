#include <string>
#include <vector>

#define DNA		"ACGT"

using namespace std;

#ifndef TSWITCH_H
#define TSWITCH_H
struct TSwitch
{
	double z;
	unsigned int k;
	string pattern_file_name;
	string text_file_name;
	string output_file_name;
};
#endif

int decode_switches ( int argc, char * argv[], TSwitch * sw );
void usage ( void );
int read ( string filename, char mod );
void match ( vector < unsigned int > * Occ );
void Index ( unsigned int q, unsigned int size, unsigned int * M );
string Num2Str ( unsigned int id, unsigned int length );
unsigned int Str2Num ( string x );
void factor ( int a, int q, string x, double p, vector<string> * list );
bool verify ( unsigned int a );
