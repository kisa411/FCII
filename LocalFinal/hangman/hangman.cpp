//
//  hangman.cpp
//  hangman
//
//  Created by Emily Koh on 4/9/16.
//  Copyright © 2016 Emily Koh. All rights reserved.
//

#include "hangman.h"
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <ctype.h>
#include <vector>
using namespace std;

Hangman::Hangman(SDL_Window* gWindow, SDL_Renderer* gRenderer ) : gTextTexture(gWindow, gRenderer), gBackgroundTexture(gWindow, gRenderer), gInputTextTexture(gWindow, gRenderer), gPromptTextTexture(gWindow, gRenderer) { //constructor
    points = 300; //set default point value as 300, and for each category of guesses the player takes to solve the puzzle deduct 50 points - player gets 12 guesses for letters to get the word right
}

int Hangman::playPuzzle() { //play the puzzle
    
    //Render text
    SDL_Color textColor = { 0, 0, 0 };
    if( !gTextTexture.loadFromRenderedText( "On the side of the road, you see a cat hanging for dear life on a tree! You can help the cat come down the tree only if you're able to solve this hangman puzzle in twelve guesses. Hurry!\n", textColor ) ) {
        printf( "Failed to render text texture!\n" );
    }
    
    bool complete = false;
    int guess=0, tries=12, npos=-1;
    char letter;
    vector <char> guessedLetters;
    string word = ("PUFFERFISH"); //answer to hangman puzzle
    string display = ".........."; //if user gets a letter right, then the letter will show; if not then it remains an "_"
    
    //word to solve is: pufferfish
    while ( tries>0 ) {
        cout << "You have " << tries << " guess(es) left!" << endl;
        guess++; //increment the number of guesses the player takes to solve the puzzle
        tries--; //decrement the number of tries the player has to solve the puzzle
        
        
        cout << "Here's the word before your guess: " << display << endl;
        
        if( !gTextTexture.loadFromRenderedText( "What letter would you like to try?\n", textColor ) ) {
            printf( "Failed to render text texture!\n" );
        }
        
        cin >> letter;
        if ( ::islower(letter) ) { //if user inputs a lower case letter
            letter = ::toupper( letter ); //standardize user input to capital letters
        }
        
        //add the letter to guessed letters
        if ( find(guessedLetters.begin(), guessedLetters.end(), letter) != guessedLetters.end() ) {
            
            if( !gTextTexture.loadFromRenderedText( "You already guessed that letter, try another letter.\n", textColor ) ) {
                printf( "Failed to render text texture!\n" );
            }
            
            guess--;
            tries++;
            continue;
        } else {
            guessedLetters.push_back(letter); //add the letter to guessed letters
        }
        
        while ( word.find(letter) != npos ) { //look for the letter in the word
            int letterPosition = word.find(letter);
            word[letterPosition] = '.'; //change the letter to . so that it won't be found again
            display[letterPosition] = letter; //display the letter in the hangman game
            word.find(letter);
        }
        
        
        cout << "Here's the word after your guess: " << display << endl << endl;
        
        if ( display.find('.') == npos) { //underscores no longer exist in the display string, the word was completed, hangman puzzle was solved
            if( !gTextTexture.loadFromRenderedText( "You solved the puzzle! Congrats! Now let's go save that cat!\n", textColor ) ) {
                printf( "Failed to render text texture!\n" );
            }
            
            complete = true;
            tries=0;
        } else if ( tries==0 ) { //player has run out of tries
            if( !gTextTexture.loadFromRenderedText( "This was your last chance to guess a letter but you weren't able to solve the hangman puzzle! :(\n", textColor ) ) {
                printf( "Failed to render text texture!\n" );
            }
            
            complete = false;
        }
        
    }
    
    if ( guess>=1 && guess<9 && complete==true ) { //player receives quality sushi (1~8)
        if( !gTextTexture.loadFromRenderedText( "Wow! You got the word right in less than 9 guesses! You were able to quickly save the cat and the cat was so impressed with you he gave you some A-grade quality sushi for your recipe!\n", textColor ) ) {
            printf( "Failed to render text texture!\n" );
        }
        
        //no deduction in points
        points = 300;
        
        //display picture
        //TODO
        
    } else if ( guess>=9 && guess<11 && complete==true ) { //player receives raw fish (9~10)
        if( !gTextTexture.loadFromRenderedText( "Wow! You were able to solve the puzzle in less than 11 guesses! You were able to save the cat and the cat was pretty happy with you so he gave you a raw fish for your recipe!\n", textColor ) ) {
            printf( "Failed to render text texture!\n" );
        }
        
        //50 point deduction in points
        points = 250;
        
        //display picture
        //TODO
        
    } else if ( guess>=11 && complete==true ) { //player receives fish bones (11~12)
        if( !gTextTexture.loadFromRenderedText( "Hm...well you were able to solve the puzzle in less than 13 guesses and were able to save the cat before he fell off the tree. The cat gave you some of his leftover fish bones partly because he was grateful but mostly out of relief that he hadn't fallen completely out of the tree.\n", textColor ) ) {
            printf( "Failed to render text texture!\n" );
        }
        
        
        //100 point deduction in points
        points = 200;
        
        //display picture
        //TODO
        
    } else {
        if( !gTextTexture.loadFromRenderedText( "You took so long in solving the puzzle the cat fell off the tree and was too angry to give you anything cool except for some scratches on your face. Sorry! :(\n", textColor ) ) {
            printf( "Failed to render text texture!\n" );
        }
    }
    
    return points; //this is the amount of points to add to the player's total points
    
}



bool Hangman::loadMedia() {
    
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
        if( !gPromptTextTexture.loadFromRenderedText( "Enter Text:", textColor ) )
        {
            printf( "Failed to render prompt text!\n" );
            success = false;
        }
    }
    
    
    return success;
}





