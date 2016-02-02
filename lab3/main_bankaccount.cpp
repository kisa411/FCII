#include <iostream>
#include "bankaccount.h"
#include "loan.h"
#include "saving.h"
using namespace std;

int main () {
	Loan pirate1; //create object of Loan 
	Saving pirate2; // create object of Saving

	pirate1.printinfo();

	pirate1.getBalance(); //get the balance of the pirate's bank account (Baseclass function)

	pirate1.calculatePayment( 500 ); //make a payment of 500 galleons for the loan (initial value is 1000 galleons)

	pirate1.calculatePayment( 600 ); //more than what is needed, function will calculate the amount to take and print out remaining loan balance

	pirate2.withdrawMoney( 2000 ); //withdraw more money than is in bank account, error message should print

	pirate2.depositMoney( 1000 ); //deposit money into savings account

	pirate2.withdrawMoney( 500 ); //withdraw reasonable amount

	pirate2.printActivityLog(); //print recent banking activity

	return 0;
}