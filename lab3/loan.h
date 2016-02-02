#ifndef LOAN_H
#define LOAN_H

#include <iostream>
#include "bankaccount.h"
using namespace std;

class Loan : public BankAccount { //inheritance

public:
	Loan(); //constructor - initial loan = 1000 galleons
	void calculatePayment( int payment ); //calculates the amount of galleons owed after a certain payment

private:
	int remainingLoan, interest;

};

#endif 