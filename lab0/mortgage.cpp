#include <iostream>
#include <iomanip>
#include "mortgage.h"
using namespace std;

//constructor initializing values
Mortgage::Mortgage() {
	setPrincipal( 100000.00 );
	setRate( 5.0 );
	setPayment( 500.00 );
}

//constructor initializing values with given input
Mortgage::Mortgage( double principal, double rate, double payment ) {
	setPrincipal( principal );
	setRate( rate );
	setPayment( payment );
}

void Mortgage::setPrincipal( double givenPrincipal ) {
	principal = givenPrincipal;
}

void Mortgage::setRate( double givenRate ) {
	rate = givenRate;
}

void Mortgage::setPayment( double givenPayment ) {
	payment = givenPayment;
}

void Mortgage::credit( double value ) {
	principal = principal - value;
}

double Mortgage::getPrincipal() {
	return principal;
}

void Mortgage::amortize() {
    double remainingBalance; 
    int years, months, month = 0;

	//check to make sure the inputs are valid
    if (principal <=0 || rate <=0 || payment <=0) {
        cout << "Please recheck your inputs for the values of principal, interest rate, and desired monthly payment. Make sure the interest rate is given in decimal format!\n" << endl;
    }
    
    //print out headers
    cout << "Month\tPayment\t\tInterest\tBalance\n" << endl;
   
    remainingBalance = principal;
    double total = 0.0;
     
    while (remainingBalance>0.0) {
        double newInterest = ((rate / 100.0 * remainingBalance)/12.0);
        
             
        //check that the remaining balance will not become negative    
        if (remainingBalance - (payment + newInterest) <= 0.0) {
            payment = remainingBalance;
            remainingBalance = 0.0;
        } else {
        	remainingBalance = remainingBalance - payment + newInterest;
    	}
        
        //make sure that the remaining balance doesn't increase if monthly payment is too small
        if (remainingBalance >= principal) {
            cout << "Your monthly payment amount is too low." << endl;
            cout << "Please re-input the amount you are paying per month." << endl;
            break;
        }
        
        total += payment;

        //print out the different values
        month++;
        printf ("%d\t", month);
        printf ("$%5.2lf\t\t", payment);
        printf ("$%.2lf\t\t", newInterest);
        printf ("$%.2lf\n", remainingBalance);
       
    }   
        
   
    years = (month/12);
    months = month - (years*12);
    
    //print out the total amount paid and the time it took to pay it off
    cout << "You paid a total sum of $"<< fixed << setprecision(2) << total << " over " <<years << " years and " << months << " months." << endl;
}
