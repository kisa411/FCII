#include <iostream>
#include "rational.h"
using namespace std;

//Emily Koh
Rational::Rational() { //default constructor
	num = 1;
	den = 1;
}

Rational::Rational( int numerator, int denominator ) { //constructor with given numerator and denominator arguments
	if( calcGCD( numerator, denominator) != 0 ) { //if the given fraction can be reduced/simplified
        int GCD = calcGCD( numerator, denominator );
        //code
	} else {
		num = numerator;
		den = denominator;
	}
}

Rational Rational::add( Rational fraction ) { //add function, returns a rational
	Rational number;

	number = one+two;
	return number;
}

Rational Rational::subtract( Rational fraction ) { //subtract function
	Rational number;

	number = one-two;
	return number;
}

Rational Rational::multiply( Rational fraction ) { //multiply function
	Rational number;

	number = one*two;
	return number;
}

Rational Rational::divide( Rational fraction ) { //divide function
	Rational number;

	number = one/two;
	return number;
}

//overload << operator - need to make friend function so that it can access private data members even though it's not part of the class itself


//overload + operator
Rational Rational::operator+( const Rational& one, const Rational& two ) { //& - passes in a reference to the object
	numerator = (one.num + two.num);
	denominator = (one.den);
	if( numerator%denominator == 0 ) { //if the given fraction can be reduced/simplified
		rational = numerator/denominator;
		cout << rational << endl;
	} else {
		cout << numerator << '/' << denominator << endl;
}

//overload - operator
Rational Rational::operator-( const Rational& one, const Rational& two ) {
	numerator = (one.num - two.num);
	denominator = (one.den);
	if( numerator%denominator == 0 ) { //if the given fraction can be reduced/simplified
		rational = numerator/denominator;
		cout << rational << endl;
	} else {
		cout << numerator << '/' << denominator << endl;
}

//overload * operator
Rational Rational::operator*( const Rational& one, const Rational& two ) {
	numerator = (one.num*two.num);
	denominator = (one.den*two.den);
	if( numerator%denominator == 0 ) { //if the given fraction can be reduced/simplified
		rational = numerator/denominator;
		cout << rational << endl;
	} else {
		cout << numerator << '/' << denominator << endl;
}

//overload / operator
Rational Rational::operator/( const Rational& one, const Rational& two ) {
	numerator = (one.num*two.den);
	denominator = (one.den*two.num);
	if( numerator%denominator == 0 ) { //if the given fraction can be reduced/simplified
		rational = numerator/denominator;
		cout << rational << endl;
	} else {
		cout << numerator << '/' << denominator << endl;
}

int Rational::calcCGD( int numerator, int denominator ) {
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




