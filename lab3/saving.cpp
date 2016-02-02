#include <iostream>
#include "saving.h"
using namespace std;


Saving::Saving() : BankAccount( 1000 ) { //default constructor - call on baseclass constructor using member initialization syntax
	withdraw = 0;
	deposit = 0;
}

void Saving::withdrawMoney( int amount ) {
	int bankBalance = BankAccount::getBalance();

	cout << "You wish to withdraw " << amount << " galleons." << endl;
	if( bankBalance - amount >= 0 ) {
		withdraw = amount; //set recent withdraw to amount
		cout << "Your new balance is: " << (bankBalance - amount) << " galleons." << endl;
		bankBalance = bankBalance-amount;
		setBalance( bankBalance );
	} else {
		cout << "That would leave a negative balance. You should be more careful about your finances. Withdraw request denied." << endl;
	} cout << endl;

}

void Saving::depositMoney( int amount ) {
	int bankBalance = BankAccount::getBalance();

	cout << "You wish to deposit " << amount << " galleons." << endl;
	if( amount >= 0 ) {
		deposit = amount; //set recent withdraw to amount
		cout << "Your new balance is: " << (bankBalance + amount) << " galleons." << endl;
		bankBalance = bankBalance+amount;
		setBalance( bankBalance );
	} else {
		cout << "It's silly to deposit 0 galleons. Deposit request denied." << endl;
	} cout << endl;
}

void Saving::printActivityLog() {
	int bankBalance = BankAccount::getBalance();

	cout << "You have recently withdrawn: " << withdraw << " galleons. You have recently deposited: " << deposit << " galleons. The current balance in the account is: " << bankBalance << endl << endl;;
}



