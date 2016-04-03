#include <iostream>
#include <ctime> //for time() function
#include <cstdlib> //for srand() function
#include "cardDeck.h"
#include "NDvector.h"

using namespace std;

ostream &operator<<( ostream &output, CardDeck &deck ) { //overload << operator to display the elements of the card deck
	
	for ( int i=0; i<deck.cardDeque.getSize(); i++ ) {
		output << deck.cardDeque[i] << endl;
	}
	// output << deck.cardDeque << endl;

	return (output);

}


CardDeck::CardDeck( int n ) { //constructor - fall back value is 52
	
	for( int i=0; i<n; i++ ) {
		//cout << i << endl;
		cardDeque.push_back(i); //put integers in the deque
		// cout << cardDeque[i] << endl;
	}
	size = n;
}


int CardDeck::getSize() { //returns the size of the deque (aka. deck of cards)
	// cout << cardDeque.getSize() << endl;
	return cardDeque.getSize();
}


void CardDeck::shuffle() { //shuffles the cards using Knuth's shuffle
	
	cardDeque.shuffle();
	// // Use a different seed value so that we don't get same result each time we run this program
 //    srand ( time(NULL) );
 
 //    // Start from the last element and swap one by one. We don't need to run for the first element that's why i > 0
 //    for (int i = cardDeque.getSize()-1; i > 0; i--)
 //    {
 //        // Pick a random index from 0 to i
 //        int j = rand() % (i+1);
 
 //        // Swap arr[i] with the element at random index
 //        int temp = cardDeque.operator[](i);
	//     cardDeque.operator[](i).operator=(cardDeque.operator[](j));
	//     cardDeque.operator[](j).operator=(temp);
 //    }
}


int CardDeck::inOrder() { // returns 1 if the elements are in nondecreasing order, 0 otherwise.
	for( int i=0; i < cardDeque.getSize()-1; i++ ) { 
		if ( cardDeque[i] >= cardDeque[i+1] ) { //not in non-decreasing order

			return 0;
		} 								
	}

	return 1; //in non-decreasing order
}






