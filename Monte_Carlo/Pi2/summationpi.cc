#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>

using namespace std;



int main(int argc, char* argv[])
{
	
	int outcome,  N=10;
	double outcome2, sum =0;
	
	if(argc>1)  {
		sscanf( argv[1], "%d", &N) ;
	}
	
	// Write out a summary of parameters
	cout << "# " << argv[0] << " N=" << N << endl ;


	// Perform N experiments.
	for(int n=1; n<=N; n++) {
		outcome = n*n;
		outcome2 = 1.0 / outcome;
		sum += outcome2 ;
		//Integer variables must be converted (cast) for correct division
		cout << n << "\t" << sum << "\t" << sqrt(6.0*sum) << endl;
	}
	return 0;
}
