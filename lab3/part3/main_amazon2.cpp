#include <iostream>
#include <iomanip> //for formatting output
#include <vector> //for vector class
#include "package2.h"
#include "TwoDayPackage2.h"
#include "overnight2.h"
using namespace std;


int main () {
	//vector < DataTypeofVariable > nameOfVector 
	vector <Package *> Packages; //create a vector of pointers of type Package (Base class pointer can point to derived classes but derived class pointers can't point to base classes)

	Packages.push_back( new OvernightPackage( "Emily", 12345, 500, 2 ) ); //base class pointer now points to the derived class
	Packages.push_back( new OvernightPackage( "Jaewon", 32456, 240, 2 ) ); //.push_back adds things to the end of the vector
	Packages.push_back( new OvernightPackage( "Sally", 23454, 30, 2 ) );
	Packages.push_back( new TwoDayPackage( "Hannah", 45346, 10, 2 ) );
	Packages.push_back( new TwoDayPackage( "Regina", 10958, 40, 2 ) );
	Packages.push_back( new TwoDayPackage( "Borah", 34958, 11000, 2 ) );

	for( int i=0; i<Packages.size(); i++ ) { //loop through all the elements in the vector and print out the cost and address - use polymorphism to make calculateCost() do something different depending on the object type it's pointing to
		double cost = Packages[i]->calculateCost(); //need to use pointer syntax since the Packages vector contains pointers of type Package
		cout << "The cost of shipping this package using the Two-Day package option is: " << fixed << setprecision(2) <<  "$" << cost << endl << endl;
	}


	return 0;
}


