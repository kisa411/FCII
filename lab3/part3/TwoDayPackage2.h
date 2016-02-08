#ifndef TWODAYPACKAGE_H
#define TWODAYPACKAGE_H

#include <iostream>
#include "package2.h"
using namespace std;

class TwoDayPackage : public Package { //TwoDayPackage is a derived class of Package class

public:
	TwoDayPackage( string s = "" , int z = 0., double w = 0., double c = 0. ); //constructor
	virtual double calculateCost(); //overrides base class's calculatecost function

private:
	double flatFee;
};



#endif