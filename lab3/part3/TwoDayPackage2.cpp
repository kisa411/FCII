#include <iostream>
#include <string>
#include "TwoDayPackage2.h"
#include "package2.h"
using namespace std;

TwoDayPackage::TwoDayPackage( string s, int z, double w, double c ) : Package( s, z, w, c ) { //default constructor
	flatFee = 5.; //additional fixed cost is 5$
}

double TwoDayPackage::calculateCost() { //overrides base class's calculateCost function
	
	// double packageWeight = Package::getWeight();
	// cout << packageWeight << endl;

	// double packageCost = Package::getCost(); 
	// cout << packageCost << endl;

	double calculatedCost = Package::calculateCost(); //calculate the shipping cost without the flat fee first - get all the private data members from base class
	calculatedCost = calculatedCost + flatFee; //calculated shipping cost after addition of flat fee

	cout << "This package is for: " << Package::getName() << " and the person's zipcode is: " << Package::getzipcode() << endl;

	
	return calculatedCost;
}