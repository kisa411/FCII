#ifndef OVERNIGHT_H
#define OVERNIGHT_H

#include <iostream>
#include "package2.h"
using namespace std;

class OvernightPackage: public Package {

public:
	OvernightPackage( string s = "" , int z = 0., double w = 0., double c = 0. ); //constructor
	virtual double calculateCost(); //override base class's calculateCost function

private:
	double extraFeePerOunce;
};


#endif