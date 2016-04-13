//
//  singaporePuzzle.cpp
//  singaporePuzzle
//
//  Created by Emily Koh on 4/9/16.
//  Copyright © 2016 Emily Koh. All rights reserved.
//

#include <iostream>
#include <string>
#include "singaporePuzzle.h"

using namespace std;

SingaporeanPuzzle::SingaporeanPuzzle( SDL_Window* gWindow, SDL_Renderer* gRenderer ) : gTextTexture(gWindow, gRenderer), gBackgroundTexture(gWindow, gRenderer), gInputTextTexture(gWindow, gRenderer), gPromptTextTexture(gWindow, gRenderer) { //default constructor
    points = 0; //set initial value of points to be 0
}

void SingaporeanPuzzle::displayPuzzle() {
    //this is the robber speaking
    //Render text
    SDL_Color textColor = { 0, 0, 0 };
    if( !gTextTexture.loadFromRenderedText( "Boo! Finally caught you! We've been after the yummy stuff in your bag for a while! If you want to escape from me without any conseqences then you need to be able to prove to me that you're smart enough to solve this brainteaser. If not, then I'm going to steal some of your ingredients! Are you ready? Here's the question!\n\n", textColor ) ) {
        printf( "Failed to render text texture!\n" );
    }
//    cout << "Boo! Finally caught you! If you want to escape from me without any conseqences then you need to be able to prove to me that you're smart enough to solve this brainteaser. If not, then I'm going to steal some of your ingredients! Are you ready? Here's the question!" << endl << endl;
    
    //brainteaser
    if( !gTextTexture.loadFromRenderedText( "**************************************************************************\nMy friends Emily and Borah want to know when Luis' birthday is. Luis gives them a list of 10 possible dates.\n\n", textColor ) ) {
        printf( "Failed to render text texture!\n" );
    }
    
    if( !gTextTexture.loadFromRenderedText( "May 15, May 16, May 19\nJune 17, June 18\nJuly 14, July 16\nAugust 14, August 15, August 17\n", textColor ) ) {
        printf( "Failed to render text texture!\n" );
    }
    
    if( !gTextTexture.loadFromRenderedText( "Luis then tells Emily and Borah separately the month and day of his birthday respectively.\n\n Borah: I don't know when Luis' birthday is, but I know that Emily does not know too.\n Emily: At first I didn't know when Luis' birthday is, but I know now.\n Borah: Then I also know when Luis' birthday is.\n\n", textColor ) ) {
        printf( "Failed to render text texture!\n" );
    }

    if( !gTextTexture.loadFromRenderedText( "So when is Luis' birthday? (Please input the answer in the format MONTH-DD).\n**************************************************************************\n", textColor ) ) {
        printf( "Failed to render text texture!\n" );
    }
    
//    cout << "**************************************************************************" << endl;
//    cout << "My friends Emily and Borah want to know when Luis' birthday is. Luis gives them a list of 10 possible dates." << endl << endl;
//    cout << "May 15, May 16, May 19" << endl;
//    cout << "June 17, June 18" << endl;
//    cout << "July 14, July 16" << endl;
//    cout << "August 14, August 15, August 17" << endl << endl;
//    cout << "Luis then tells Emily and Borah separately the month and day of his birthday respectively.\n\n Borah: I don't know when Luis' birthday is, but I know that Emily does not know too.\n Emily: At first I didn't know when Luis' birthday is, but I know now.\n Borah: Then I also know when Luis' birthday is." << endl << endl;
//    cout << "So when is Luis' birthday? (Please input the answer in the format MONTH-DD)." << endl;
//    cout << "**************************************************************************" << endl;
}

int SingaporeanPuzzle::playPuzzle() { //returns the amount of points player should get
    string correct = "july-16";
    string answer;
    bool complete = false;
    int tryNumber = 0;
    
    SDL_Color textColor = { 0, 0, 0 };

    
    while ( complete == false ) {
        
        if( !gTextTexture.loadFromRenderedText( "What is your answer?\nAnswer: ", textColor ) ) {
            printf( "Failed to render text texture!\n" );
        }
//        cout << "What is your answer?" << endl;
//        cout << "Answer: " << endl;
        
        
        cin >> answer;
        tryNumber++; //increment the number of tries user takes
        for ( int j=0; j<answer.length(); j++ ) {
            answer[j] = ::tolower(answer[j]); //make the answer lower-case
        }
        if ( answer.compare(correct)==0 ) { //user's answer matches the correct answer
            
            if( !gTextTexture.loadFromRenderedText( "Congratulations! You got it correct!", textColor ) ) {
                printf( "Failed to render text texture!\n" );
            }

//            cout << "Congratulations! You got it correct!" << endl;
            complete = true;
            
            if ( tryNumber == 1 ) { //got the answer on the first try
                if( !gTextTexture.loadFromRenderedText( "You got it correct on your first try, so I won't steal anything from you this time!", textColor ) ) {
                    printf( "Failed to render text texture!\n" );
                }
                
//                cout << "You got it correct on your first try, so I won't steal anything from you this time!" << endl;
                return points;
            } else if ( tryNumber == 2 ) { //got the answer on the second try
                if( !gTextTexture.loadFromRenderedText( "You got it correct but on your second try - for wasting my time I'm going to take some stuff from you!\nOh no! The robber stole 30 points worth of ingredients from your bag!", textColor ) ) {
                    printf( "Failed to render text texture!\n" );
                }
                
//                cout << "You got it correct but on your second try - for wasting my time I'm going to take some stuff from you!" << endl;
//                cout << "Oh no! The robber stole 30 points worth of ingredients from your bag!" << endl;
                points+=30;
                return points;
            } else if ( tryNumber == 3 ) { //got the answer on the third try
                if( !gTextTexture.loadFromRenderedText( "You got it correct but on your third try - for wasting my time I'm going to take some stuff from you!\nOh no! The robber stole 60 points worth of ingredients from your bag!\n", textColor ) ) {
                    printf( "Failed to render text texture!\n" );
                }
                
//                cout << "You got it correct but on your third try - for wasting my time I'm going to take some stuff from you!" << endl;
//                cout << "Oh no! The robber stole 60 points worth of ingredients from your bag!" << endl;
                points+=60;
                return points;
            } else { //if player is unable to solve the puzzle in 3 tries,
                if( !gTextTexture.loadFromRenderedText( "But you took too long to come up with the correct answer! For wasting so much of my time I'm going to steal a lot of stuff from you!\nOh no! The robber stole 100 points worth of ingredients from your bag! You need to brush up on your logical thinking skills!", textColor ) ) {
                    printf( "Failed to render text texture!\n" );
                }
                
//                cout << "But you took too long to come up with the correct answer! For wasting so much of my time I'm going to steal a lot of stuff from you!" << endl;
//                cout << "Oh no! The robber stole 100 points worth of ingredients from your bag! You need to brush up on your logical thinking skills!" << endl;
                points+=100;
                return points;
            }
        } else {
            if( !gTextTexture.loadFromRenderedText( "That's wrong, try again.\n", textColor ) ) {
                printf( "Failed to render text texture!\n" );
            }
            
//            cout << "That's wrong, try again." << endl;
        }
    }
    
    
    return points;
}

bool SingaporeanPuzzle::loadMedia() {
    
    //Loading success flag
    bool success = true;
    
    //Open the background picture
    if( !gBackgroundTexture.loadFromFile( "alphabetpuzzle.png" )) //need to change pictures to display
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







