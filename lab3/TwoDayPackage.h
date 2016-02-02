#ifndef TWODAYPACKAGE_H
#define TWODAYPACKAGE_H

#include <iostream>
#include "package.h"
using namespace std;

class TwoDayPackage : public Package { //TwoDayPackage is a derived class of Package class

public:
	TwoDayPackage(); //constructor
	double calculateCost(); //overrides base class's calculatecost function

private:
	double flatFee;
};



#endif