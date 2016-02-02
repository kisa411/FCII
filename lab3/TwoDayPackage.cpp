#include <iostream>
#include <string>
#include "TwoDayPackage.h"
#include "package.h"
using namespace std;

TwoDayPackage::TwoDayPackage() : Package( "Emily", 97229, 100, 2 ) { //default constructor
	flatFee = 5.; //additional fixed cost is 5$
}

double TwoDayPackage::calculateCost() { //overrides base class's calculateCost function
	
	// double packageWeight = Package::getWeight();
	// cout << packageWeight << endl;

	// double packageCost = Package::getCost(); 
	// cout << packageCost << endl;

	double calculatedCost = Package::calculateCost(); //calculate the shipping cost without the flat fee first - get all the private data members from base class
	calculatedCost = calculatedCost + flatFee; //calculated shipping cost after addition of flat fee


	
	return calculatedCost;
}