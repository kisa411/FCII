#include <iostream>
#include <string>
#include "package.h"
using namespace std;

Package::Package( string n, int z, double w, double c ) { //default constructor - takes in name, zipcode, package weight and cost as paramters
	name = n;
	zipcode = z;

	if( w>=0 && c>=0 ) { //check to make sure inputs are non-negative
		weight = w;
		cost = c;
	} else {
		cout << "One or both of the given values is not non-negative. Please check your input values." << endl;
	}
}


double Package::calculateCost() { //calculate shipping cost of package
	double calculatedCost;

	calculatedCost = weight * cost;

	return calculatedCost;
}

double Package::getCost() {

	return cost;
}

double Package::getWeight() {

	return weight;
}

