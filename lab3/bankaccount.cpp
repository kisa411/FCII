#include <iostream>
#include "bankaccount.h"
using namespace std;

BankAccount::BankAccount( int amount ) { //constructor
	balance = amount;
	address = "Oceania";
	bank = "Pirate Bank";
}

int BankAccount::getBalance() {
	cout << "The current balance in the account is: " << balance << endl << endl;
	return balance;
}

void BankAccount::printinfo() {
	cout << "This bank is called: " << bank << " and it's located in: " << address << endl << endl;
}

void BankAccount::setBalance( int amount ) {
	balance = amount;
}




