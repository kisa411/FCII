#include <iostream>
using namespace std;

/*program about estimating pi based on user-input given value of terms
17 January 2016
*/

double approximator( int terms );

int main () {
	int terms, i;
	double approximation;

	cout << "Please enter the number of terms in the series." << endl;
	cin >> terms;
	if (terms <= 2) {
		cout << "The provided value must be equal to or greater than 2! Please re-enter the number of terms in the series." << endl;
		cin >> terms;
	}

	for ( i=1; i<=terms; i++ ) {
		approximation = approximator( i );
		cout << "Estimate after " << i << " term(s): " << approximation << endl;
	}

	return 0;

}

double approximator( int terms ) {	//function to calculate the approximation
	int i;
	double approximation = 4, denom = 3;

	for ( i=1; i<terms; i++ ) {
		if ( i%2!=0 ) {	//if it's an odd numbered term, subtract
			approximation = approximation - (4/denom);
			denom +=2;	//increase denominator by 2 each term
		} else {	//if it's an even numbered term, add
			approximation = approximation + (4/denom);
			denom +=2;	//increase denominator by 2 each term
		}
	}

	return approximation;	

}



//scp <filename> ykoh1@student00.cse.nd.edu:/afs/nd.edu/courses/cse/cse20212.01/dropbox/ykoh1/<lab#>

