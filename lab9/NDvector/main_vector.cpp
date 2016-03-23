#include <iostream>
#include <ctime> //for time() function
#include <cstdlib> //for srand() function
#include <string>
#include "cardDeck.h"

using namespace std;


int main () {
	
	srand( time(0) ); //changes the seed number for the shuffle randomly - using time() allows for really random numbers since now the numbers coming out of the srand() function are based off the time 

	CardDeck deck1(52); //instantiate an object of class cardDeck

	if( deck1.inOrder() == 1 ) { //check to see if deck is in order or not
		cout << "The deck is in non-decreasing order." << endl << endl;
	} else {
		cout << "The deck is not in non-decreasing order." << endl << endl;
	}

	cout << "Here's the deck before shuffling: " << deck1 << endl; //print out cards before shuffle

	deck1.shuffle(); //shuffle the deck into a random order

	cout << "Here's the deck after shuffling: " << deck1 << endl; //print out cards after shuffle


	return 0;
}





