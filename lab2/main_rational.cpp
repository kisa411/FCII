#include <iostream>
#include "rational.h"
using namespace std;

//Emily Koh

int main() {
	int numerator, denominator;

	cout << "What is the numerator of the first rational?" << endl;
	cin >> numerator;
	cout << "What is the denominator of the first rational?" << endl;
	cin >> denominator;
	while( denominator == 0 ) { 
		cout << "The denominator's not valid - please put in a non-zero value." << endl;
		cout << "What is the denominator of the first rational?" << endl;
		cin >> denominator;
	}

	Rational fraction1( numerator, denominator ); //instantiate object of Rational class

	cout << "What is the numerator of the second rational?" << endl;
	cin >> numerator;
	cout << "What is the denominator of the second rational?" << endl;
	cin >> denominator;
	while( denominator == 0 ) { 
		cout << "The denominator's not valid - please put in a non-zero value." << endl;
		cout << "What is the denominator of the first rational?" << endl;
		cin >> denominator;
	}

	Rational fraction2( numerator, denominator ); //instantiate object of Rational class

	return 0;
}


