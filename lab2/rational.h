#ifndef RATIONAL_H
#define RATIONAL_H

//Emily Koh
#include <iostream>
using namespace std;

class Rational() {
	friend ostream &operator<<( ostream &, C4Board& board ); //overload << operator so that cout << board can actually display the board - parameters: what array to use to store the output, what class to act on (goes before public or private categories)

	public:
		Rational(); //default constructor
		Rational( int numerator, int denominator ); //non-default constructor
		Rational add( ... ); //add function that adds two rationals
		Rational subtract( ... ); //subtract function that subtracts one rational from the other
		Rational multiply( ... ); //multiply function that multiplies two rationals
		Rational divide( ... ); //divide function that divides one rational from the other
		Rational operator+( Rational& one ); //overload + operator
		Rational operator-( Rational& one ); //overload - operator
		Rational operator*( Rational& one ); //overload * operator
		Rational operator/( Rational& one ); //overload / operator
	private:
		int num, den; //numerator and denominator
}

#endif
