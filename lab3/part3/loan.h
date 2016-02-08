#ifndef LOAN_H
#define LOAN_H

#include <iostream>
#include "bankaccount.h"
using namespace std;

class Loan { //no longer inheriting from base class

public:
	Loan(); //constructor - initial loan = 1000 galleons
	void calculatePayment( int payment ); //calculates the amount of galleons owed after a certain payment
	BankAccount account1(); //variable of type BankAccount class - run constructor when declaring variable

private:
	int remainingLoan, interest;

};

#endif 