#ifndef CARDDECK_H
#define CARDDECK_H

#include <iostream>
#include <ctime> //for time() function
#include <cstdlib> //for srand() function
#include "NDvector.h"

using namespace std;


class CardDeck {

friend ostream &operator<<( ostream &output, CardDeck &deck ); //overload << operator so that cout << board can actually display the board - parameters: what array to use to store the output, what class to act on (goes before public or private categories)

public:
	CardDeck( int n=52 ); //constructor
	int getSize(); //returns the size of the current deck of cards
	int inOrder(); // returns 1 if the elements are in nondecreasing order (i.e., A[i] <= A[i + 1] for all cards in the deck), 0 otherwise.
	void shuffle(); //shuffles the cards using Knuth's shuffle
	
private:
	NDvector<int> cardDeque;
	int size;
	
};


#endif