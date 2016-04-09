//
//  main.cpp
//  blackjack
//
//  Created by Emily Koh on 4/9/16.
//  Copyright © 2016 Emily Koh. All rights reserved.
//

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <sstream>
#include "cardDeck.hpp"
#include "sdl_win_wrap.hpp"
#include "texture.hpp"
using namespace std;

int playBlackJack() {
    int points=0;
    
     SDL_Win_Wrap window_instance; //SDL window object
    
    //create an object of class CardDeck
    CardDeck blackjack( window_instance.getWindow(), window_instance.getRenderer(), 52 ); //blackjack object
    
    //initialize all the necessary variables
    int playerWins=0, dealerWins=0, playerTotal=0, dealerTotal=0;
    int size = blackjack.getSize(); //store the initial number of cards in the deck(should be 52)
    int choice, card, dealerPlay = 1; //0 = no, 1 = yes
    string hitorstand = "hit"; //start with hit
    
    cout << "Would you like to play a game of blackjack? 1 for yes and 0 for no." << endl;
    cin >> choice;
    
    while ( choice == 1 ) {
        blackjack.shuffle(); //shuffle the deck so that they're in random order
        playerTotal = 0; //reset player total
        dealerTotal = 0; //reset dealer total
        while ( size>=15 ) { //while there are 15 or more cards, play the game
            
            if ( hitorstand == "hit" ) { //player's turn - if they say stand then they would no longer be able to get a card
                card = blackjack.player(); //give the player a card
                playerTotal += card; //add the card's value to the player's total
                cout << "Your total is: " << playerTotal << endl;
                if ( playerTotal > 21 ) {
                    cout << "Sorry, your total went over 21. You lose!" << endl;
                    break;
                }
                size--; //decrease the number of cards in the deck by one
            }
            //dealer's turn - automatically gets a card unless value goes up to 17 or greater
            if ( dealerPlay == 1 ) {
                card = blackjack.dealer(); //give the dealer a card
                dealerTotal += card;
                cout << "The dealer total now is " << dealerTotal << endl;
                size--;
                cout << "The dealer has received a card." << endl;
                if (dealerTotal >= 17 ) { //if the dealer's total reaches 17 or higher then they stop
                    dealerPlay = 0;
                    //cout << "The dealer is no longer taking any cards." << endl;
                }
            }
            cout << "Would you like to hit or stand? Please put either \"hit\" or \"stand\" " << endl;
            cin >> hitorstand;
            if ( hitorstand == "stand" || hitorstand == "hit" ) {
                if ( dealerPlay == 0 && hitorstand == "stand" ) {
                    break; //if player stands and the dealer is also not taking any more cards, finish the game
                } else if ( dealerPlay == 1 && hitorstand == "stand" ) {
                    continue; //if player stands but the dealer is taking more cards, then continue the game so that the dealer can take a card
                }
                continue; //if the player hits then continue the game
            }
            else {
                cout << "Sorry, could not process input. Please put either \"hit\" or \"stand\" " << endl;
                cin >> hitorstand;
            }
        }
        
        if ( (size < 15 && dealerPlay == 1) || (size < 15 && hitorstand == "hit") ) { //if there's less than 15 cards and the dealer is still receiving cards or the player wants to get another card
            cout << "The deck has less than 15 cards now, would you like to continue playing? Put in 1 for yes or 0 for no." << endl;
            cin >> choice;
            //if the deck goes below 15 cards, "open" a new deck
            if ( choice == 1 ) {
                blackjack.reset();
                dealerPlay == 1;
                hitorstand = "hit";
            } else if ( choice == 0 ) { //player does not want to play with a new deck
                cout << "Another game will not be started." << endl;
            }
        }
        
        //announce the results of this round
        if ( playerTotal > dealerTotal ) {
            if ( playerTotal <= 21 ) {
                cout << "The player has won this round. Congratulations! You can leave the casino now." << endl;
                playerWins++;
            } else {
                cout << "Sorry, the dealer won this round." << endl;
                dealerWins++;
            }
            cout << "You had: " << playerTotal << " and the dealer had: " << dealerTotal << endl << endl;
            choice = 1; //this starts a new game
        } else if ( dealerTotal > playerTotal ) {
            if ( dealerTotal <= 21 ) {
                cout << "The dealer has won this round. The dealer's total was: " << dealerTotal << endl;
                dealerWins++;
            } else {
                cout << "The player has won this round! Congratulations!" << endl;
                playerWins++;
            }
            cout << "You had: " << playerTotal << " and the dealer had: " << dealerTotal << endl << endl;
            choice = 1; //this starts a new game
        } else if ( playerTotal == dealerTotal ) {
            cout << "This round was a tie. The totals for both the player and the dealer were: " << playerTotal << endl;
            cout << "You had: " << playerTotal << " and the dealer had: " << dealerTotal << endl << endl;
            choice = 0; //end current blackjack game
        }
    }
    
    if ( playerWins>dealerWins ) {
        cout << "You beat the dealer so you get something really good for your ingredient stash!" << endl;
        points+=100;
        cout << "The dealer says: Come back again soon! :)" << endl;
        return points;
    } else if ( dealerWins>playerWins ) {
        cout << "The dealer beat you so you have to give up something really yummy." << endl;
        points-=50;
        cout << "The dealer says: Come back again soon! :)" << endl;
        return points;
    } else {
        cout << "Seems like the game ended in a tie. You don't get any penalties or rewards - oh well! Could've been worse!" << endl;
        cout << "The dealer says: Come back again soon! :)" << endl;
        return points;
    }
    
}

int main () {
    int pointsEarned;
    
    srand( time(0) ); //changes the seed number for the shuffle randomly - using time() allows for really random numbers since now the numbers coming out of the srand() function are based off the time

    
    /*BLACKJACK GAME*/
    pointsEarned = playBlackJack();
    //add points earned to player's total points
    
    return 0;
}

