#ifndef PACKAGE_H
#define PACKAGE_H

#include <iostream>
#include <string>
using namespace std;

class Package {

public:
	Package( string = "" , int z = 0., double w = 0., double c = 0. ); //constructor - set the default values in the constructor, but if other values are given then the new values become the variable values
	virtual double calculateCost() = 0; //calculates the cost to ship a package (cost per ounce X weight of item) - makes it into a pure virtual function, not class Package is abstract and all derived classes must provide an implementation for calculateCost
	double getWeight(); //returns weight variable value
	double getCost(); //returns cost variable value
	string getName(); //returns name 
	int getzipcode(); //returns zipcode

private:
	string name;
	int zipcode;
	double weight, cost; //check to make sure both are non-negative
};



#endif 