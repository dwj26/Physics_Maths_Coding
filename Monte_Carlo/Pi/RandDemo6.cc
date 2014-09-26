#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

#define ranf() \
	((double)random()/(1.0+(double)0x7fffffff)

int main(int argc, char* argv[])
{
	int outcome, N=10, count_in = 0, seed = 123;
	double fraction_in;
	
	if(argc>1)  {
		sscanf( argv[1], "%d", &N) ;
	}
	if(argc>2) {
		sscanf( argv[2], "%d", &seed ) ; // put the 2nd argument in seed
	}
	// Write out a summary of parameters
	cout << "# " << argv[0] << " N=" << N << " seed=" << seed << endl ;

	// Initialise random number generator
	srandom(seed);

	// Perform N experiments.
	for(int n=1; n<=N; n++) {
		double x = ranf(); 	// ranf() returns a real number in [0,1)
		double y = ranf() ;
		outcome = ( x*x + y*y < 1.0 ) ? 1 : 0 ;
		count_in += outcome ;
		//Integer variables must be converted (cast) for correct division
		fraction_in = static_cast<double>(count_in)/n;
		cout << x << "\t" << y << "\t"
		<< count_in << "\t" << n << "\t" << 4.0 * fraction_in << endl;
	}
	return 0;
}
