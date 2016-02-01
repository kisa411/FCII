#include <iostream>
#include <cmath>
#include "rational.h"
using namespace std;

//Emily Koh
Rational::Rational() { //default constructor
	num = 1;
	den = 1;
}

Rational::Rational( int numerator, int denominator ) { //constructor with given numerator and denominator arguments
	if( calcGCD( numerator, denominator) >= 1 ) { //if the given fraction can be reduced/simplified, simplify using GCD
        int GCD = calcGCD( numerator, denominator );
        num = numerator/GCD;
        den = denominator/GCD;
	} else {
		num = numerator;
		den = denominator;
	}
}

//overload << operator - need to make friend function so that it can access private data members even though it's not part of the class itself
ostream &operator<<( ostream& output, Rational& r) { //overload '<<' operator so that you can print out rational numbers
    output << r.num << "/" << r.den;
    
    return output;
}

//overload + operator
Rational Rational::operator+( Rational& two ) { //& - passes in a reference to the object
	Rational value;
    
    value.num = ((num*two.den)+(two.num*den)); //num = numerator of object that the + operator is getting called on
	value.den = (den*two.den); //den = denominator of object that the + operator is getting called on
    if( calcGCD( value.num, value.den ) >= 1 ) { //if the given fraction can be reduced/simplified, simplify using GCD
        int GCD = calcGCD( value.num, value.den );
        value.num = value.num/GCD;
        value.den = value.den/GCD;
        return value;
    } else {
        return value;
    }
}

//overload - operator
Rational Rational::operator-( Rational& two ) {
    Rational value;
    
    value.num = ((num*two.den)-(den*two.num)); //num = numerator of object that the + operator is getting called on
    value.den = (den*two.den); //den = denominator of object that the + operator is getting called on
    if( calcGCD( value.num, value.den ) >= 1 ) { //if the given fraction can be reduced/simplified, simplify using GCD
        int GCD = calcGCD( value.num, value.den );
        value.num = value.num/GCD;
        value.den = value.den/GCD;
        return value;
    } else {
        return value;
    }
}

//overload * operator
Rational Rational::operator*( Rational& two ) {
    Rational value;
    
    value.num = (num*two.num);
	value.den = (den*two.den);
    if( calcGCD( value.num, value.den ) >= 1 ) { //if the given fraction can be reduced/simplified, simplify using GCD
        int GCD = calcGCD( value.num, value.den );
        value.num = value.num/GCD;
        value.den = value.den/GCD;
        return value;
    } else {
        return value;
    }
}

//overload / operator
Rational Rational::operator/( Rational& two ) {
    Rational value;
    
    value.num = (num*two.den);
	value.den = (den*two.num);
    if( calcGCD( value.num, value.den ) >= 1 ) { //if the given fraction can be reduced/simplified, simplify using GCD
        int GCD = calcGCD( value.num, value.den );
        value.num = value.num/GCD;
        value.den = value.den/GCD;
        return value;
    } else {
        return value;
    }
}

//overload ! operator - gives inverse
void Rational::operator!() {
    //Rational value;
    int temp;
    
    temp = num; //put numerator in temporary variable
    num = den;
    den = temp;
//    value.num = den; //set numerator to denominator
//    value.den = num; //set denominator to temporary variable
    cout << "The inverse of the specified rational is: " << num << "/" << den << endl;
    
}
    
int Rational::calcGCD( int numerator, int denominator ) {
    int tmp;
    numerator = abs( numerator );
    denominator = abs( denominator );
    while (numerator > 0) {
        tmp = numerator;
        numerator = denominator % numerator;
        denominator = tmp;
    }
    return denominator;
}





