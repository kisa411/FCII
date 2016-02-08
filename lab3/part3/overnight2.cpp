#include <iostream>
#include <string>
#include "overnight2.h"
#include "package2.h"
using namespace std;

OvernightPackage::OvernightPackage( string s, int z, double w, double c ) : Package( s, z, w, c ) { //constructor -  "Emily", 97229, 100, 2 
	extraFeePerOunce = 0.1;
}

double OvernightPackage::calculateCost() { //override base class calculateCost function

	// double packageWeight = Package::getWeight();
	// cout << packageWeight << endl;

	// double packageCost = Package::getCost(); 
	// cout << packageCost << endl;

	double calculatedCost = Package::calculateCost(); //calculate the shipping cost without the flat fee first - get all the private data members from base class
	calculatedCost = calculatedCost + (Package::getCost() * extraFeePerOunce); //calculated shipping cost after addition of extraFeePerOunce

	cout << "This package is for: " << Package::getName() << " and the person's zipcode is: " << Package::getzipcode() << endl;
	
	return calculatedCost;

}