#include <iostream>
#include <iomanip> //for formatting output
#include "package.h"
#include "TwoDayPackage.h"
#include "overnight.h"
using namespace std;


int main () {
	Package standardPackage( "Emily", 97229, 100, 2 );
	TwoDayPackage twoDayPackage;
	OvernightPackage overnightPackage;

	double standard, twoDay, overnight;

	
	standard = standardPackage.calculateCost(); //good example
	cout << "The cost of shipping this package using the standard option is: " << fixed <<setprecision(2) << "$" << standard << endl;

	twoDay = twoDayPackage.calculateCost(); //good example
	cout << "The cost of shipping this package using the Two-Day package option is: " << fixed << setprecision(2) <<  "$" << twoDay << endl;

	overnight = overnightPackage.calculateCost(); //good example
	cout << "The cost of shipping this package using the overnight option is: " << fixed << setprecision(2) <<  "$" << overnight << endl;



	Package standardPackage2( "Emily", 97229, -10, -3 ); //bad example with negative inputs


	return 0;
}


