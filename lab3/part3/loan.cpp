#include <iostream>
#include "loan.h"
using namespace std;

Loan::Loan() { //default constructor - call on baseclass constructor using member initialization syntax 
	remainingLoan = 1000; //initial loan amount is 1000 galleons
	interest = 10;
}

void Loan::calculatePayment( int payment ) {
	cout << "You would like to pay " << payment << " galleons." << endl;
	if( (remainingLoan + interest) - payment >= 0 ) {
		remainingLoan = remainingLoan + interest - payment;
		cout << "You still have to pay " << remainingLoan << " galleons." << endl;
	} else {
		cout << "You only need to pay " << remainingLoan << " so I will only accept " << (remainingLoan) << " galleons." << endl;
		remainingLoan = 0;
	}
	cout << endl;
}
