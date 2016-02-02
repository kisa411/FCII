#ifndef SAVING_H
#define SAVING_H

#include <iostream>
#include "bankaccount.h"
using namespace std;

class Saving : public BankAccount { //inheritance

public:
	Saving(); //constructor
	void withdrawMoney( int amount ); //withdraw galleons
	void depositMoney( int amount ); //deposit galleons
	void printActivityLog(); //print out activity log based on a certain action

private:
	int withdraw, deposit; //amount of galleons to withdraw, amount of galleons to deposit (galleons will only be in integer values)


};

#endif 