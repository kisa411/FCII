#include <iostream>
using namespace std;

class Mortgage {
	public:
		Mortgage();	//constructor
		Mortgage( double principal, double rate, double payment ); 	//non-default constructor with parameter values
		void credit( double value );	//deducts value from remaining principal
		double getPrincipal();	//returns the current principal remaining
		void amortize();	//calculates and displays a correct and clean amortization table
		void setPrincipal( double givenPrincipal );
		void setRate( double givenRate );
		void setPayment( double givenPayment ); 


	private:
		double principal, rate, payment;
};