//
//  blackjack.cpp
//  blackjack
//
//  Created by Emily Koh on 4/9/16.
//  Copyright © 2016 Emily Koh. All rights reserved.
//

#include "cardDeck.h"
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <iostream>
#include <deque>
#include <vector>
#include <algorithm> //for shuffle() function
#include <ctime> //for time() function
#include <cstdlib> //for srand() function

using namespace std;

ostream &operator<<( ostream &output, CardDeck &deck ) { //overload << operator to display the elements of the card deck
    deque<int>::const_iterator i; //make an iterator so that program can go through each element of the cardDeque deque and print it out
    
    for( i = deck.cardDeque.begin(); i != deck.cardDeque.end()-1; ++i ) { //assigns const_iterator i to start from the beginning of the deque to the end of the deque - deck is a copy of the class, and cardDeque is the data member I want to access from class deck
        cout << *i << ", "; //* is necessary so that it prints out the value that the iterator is pointing to
    }
    
    deque<int>::const_reverse_iterator reverse; //reverse iterator for syntatical reasons - don't want "0, 1, 2, 3, 4, 5, 6, 7, 8, 9, " -- want "0, 1, 2, 3, 4, 5, 6, 7, 8, 9"
    reverse = deck.cardDeque.rbegin(); //last element of deque
    cout << *reverse;
    cout << endl;
    
    // vector<CardDeck* >::const_iterator j;
    
    // for( j = deck.cardDecks.begin(); j != deck.cardDecks.end(); ++j ) {
    // 	cout << *j << ", "; //* is necessary so that it prints out the value that the iterator is pointing to
    // }
    
    return (output);
    
}


CardDeck::CardDeck( SDL_Window* gWindow, SDL_Renderer* gRenderer, int n ) : gTextTexture(gWindow, gRenderer), gBackgroundTexture(gWindow, gRenderer), gInputTextTexture(gWindow, gRenderer), gPromptTextTexture(gWindow, gRenderer)  { //constructor - fall back value is 52
    
    for( int i=0; i<n; i++ ) {
        cardDeque.push_back(i); //put integers in the deque
    }
    size = n;
}


int CardDeck::getSize() { //returns the size of the deque (aka. deck of cards)
    
    return cardDeque.size();
}


void CardDeck::shuffle() { //shuffles the cards using random_shuffle algorithm of STL
    
    // long random = rand();
    
    deque<int>::const_iterator i; //create an iterator for the deque datatype
    
    random_shuffle( cardDeque.begin(), cardDeque.end() ); //randomly shuffles the cardDeque - range is [cardDeque.begin(), cardDeque.end()) **from first element up to specified last element
    
    // for( i = cardDeque.begin(); i != cardDeque.end(); ++ i ) { //test to see the order of the shuffled cards
    // 	cout << *i << endl;
    // }
}


int CardDeck::inOrder() { // returns 1 if the elements are in nondecreasing order, 0 otherwise.
    for( int i=0; i < cardDeque.size()-1; i++ ) {
        if ( cardDeque[i] >= cardDeque[i+1] ) { //not in non-decreasing order
            return 0;
        }
    }
    
    return 1;									//in non-decreasing order
}


void CardDeck::printReverse() { //prints the cards in a reverse order
    
    deque<int>::const_reverse_iterator reverse;
    deque<int>::const_reverse_iterator end = cardDeque.rend()-1;
    
    for( reverse=cardDeque.rbegin(); reverse != end; ++reverse ) { //start from the end of the deque, and the print until the first element of deque
        cout << *reverse << ", ";
    }
    
    deque<int>::const_iterator i; //make an iterator
    i = cardDeque.begin();
    cout << *i; //first element of deque (but in reverse order so basically the first element of deque)
    cout << endl;
    
}


void CardDeck::monkeySort() { //do the monkeysort function - calculate how many random shuffles it takes to randomly shuffle the deque into non-descending order
    
    
    cardDecks.push_back( new CardDeck( gWindow, gRenderer, 7));
    cardDecks.push_back( new CardDeck( gWindow, gRenderer, 7));
    cardDecks.push_back( new CardDeck( gWindow, gRenderer, 7));
    
    cardDecks.push_back( new CardDeck( gWindow, gRenderer, 8));
    cardDecks.push_back( new CardDeck( gWindow, gRenderer, 8));
    cardDecks.push_back( new CardDeck( gWindow, gRenderer, 8));
    
    cardDecks.push_back( new CardDeck( gWindow, gRenderer, 9));
    cardDecks.push_back( new CardDeck( gWindow, gRenderer, 9));
    cardDecks.push_back( new CardDeck( gWindow, gRenderer, 9));
    
    for( int i=0; i<cardDecks.size(); i++ ) { //do the initial random shuffles
        cardDecks[i]->shuffle();
    }
    
    for( int i=0; i<cardDecks.size(); i++ ) {
        int count = 0;
        while (cardDecks[i]->inOrder()==0 ) { //while the current order doesn't match the initial order
            cardDecks[i]->shuffle(); //shuffle again
            count++; //increase the count
        }
        
        // vector<CardDeck* >::const_iterator j;
        
        //print out the card deck after it's been sorted again
        // for( j = cardDecks.begin(); j != cardDecks.end(); ++j ) {
        // 	cout << *j << ", "; //* is necessary so that it prints out the value that the iterator is pointing to
        // }
        
        // for (int j=0; j<cardDecks.size(); j++ ) {
        // 	cout << cardDecks[j] << endl;
        // }
        cout << count << endl;
    }
}

int CardDeck::player() { //"deal" a card - using pop_back() on the deque & return the card value
    
    //pop out a random card from the end of the deque
    int i = cardDeque[size]; //store the value of the number in a variable
    cardDeque.pop_back(); //delete the last element
    size--;
    
    i = (i%12)+1; //convert the number values to the playing card values
    
    if (i==1) { //is an ace
        cout << "Ace(11)" << endl;
        i=11;
    } else if (i==11) { //is a jack
        cout << "Jack(10)" << endl;
        i=10;
    } else if (i==12) { //is a queen
        cout << "Queen(10)" << endl;
        i=10;
    } else if (i==13) { //is a king
        cout << "King(10)" << endl;
        i=10;
    }
    
    return i;
}

int CardDeck::dealer() { //"deal" a card - using pop_back() on the deque & return the card value - don't tell the user the value the dealer gets though since it should be secret
    
    //pop out a random card from the end of the deque
    int i = cardDeque[size]; //store the value of the number in a variable
    cardDeque.pop_back(); //delete the last element
    size--;
    
    i = (i%12)+1; //convert the number values to the playing card values (1~12)
    
    if (i==1) { //is an ace
        //cout << "Ace(11)" << endl;
        i=11;
    } else if (i==11) { //is a jack
        //cout << "Jack(10)" << endl;
        i=10;
    } else if (i==12) { //is a queen
        //cout << "Queen(10)" << endl;
        i=10;
    } else if (i==13) { //is a king
        //cout << "King(10)" << endl;
        i=10;
    }
    
    return i;
}

void CardDeck::reset() { //clean up the old deck and then create a new deck
    
    cardDeque.erase(cardDeque.begin(), cardDeque.end()); //erase all the elements in the deque
    
    for( int i=0; i<52; i++ ) {
        cardDeque.push_back(i); //put integers in the deque
    }
    
    size = 52;
    
    
}

bool CardDeck::loadMedia() {
    
    //Loading success flag
    bool success = true;
    
    //Open the background picture
    if( !gBackgroundTexture.loadFromFile( "alphabetpuzzle.png" ))
    {
        printf( "Failed to load background image texture!\n" );
        success = false;
    }
    
    //Open the font
    gFont = TTF_OpenFont( "AmaticSC-Regular.ttf", 28 );
    if( gFont == NULL )
    {
        printf( "Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError() );
        success = false;
    }
    else
    {
        //Render the prompt
        SDL_Color textColor = { 0, 0, 0, 0xFF };
        if( !gPromptTextTexture.loadFromRenderedText( "Hit or Stand?: ", textColor ) )
        {
            printf( "Failed to render prompt text!\n" );
            success = false;
        }
    }
    
    
    return success;
}




