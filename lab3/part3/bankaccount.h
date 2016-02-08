#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <iostream>
#include <string>
using namespace std;

class BankAccount {

public:
	BankAccount(); 
	BankAccount( int amount ); //constructor
	int getBalance(); //print out balance
	void printinfo(); //print out bank information
	void setBalance( int amount ); //set balance

private:
	int balance; //balance in account
	string address, bank;
};


#endif