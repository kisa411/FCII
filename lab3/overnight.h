#ifndef OVERNIGHT_H
#define OVERNIGHT_H

#include <iostream>
#include "package.h"
using namespace std;

class OvernightPackage: public Package {

public:
	OvernightPackage(); //constructor
	double calculateCost(); //override base class's calculateCost function

private:
	double extraFeePerOunce;
};


#endif