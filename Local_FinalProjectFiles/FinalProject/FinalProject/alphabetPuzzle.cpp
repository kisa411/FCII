//
//  alphabetPuzzle.cpp
//
/* Emily Koh
 FCII Final Project
 Spring 2016
 Alphabet Puzzle Class
 */
//  Created by Emily Koh on 3/20/16.
//  Copyright © 2016 Emily Koh. All rights reserved.
//

//Using SDL, SDL_image, SDL_ttf, standard IO, strings, and string streams
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <sstream>
#include "alphabetPuzzle.h"
#include "sdl_win_wrap.h"
#include "texture.h"

using namespace std;



AlphabetPuzzle::AlphabetPuzzle() { //default constructor
    points = 0; //set initial value of points to be 100
}

void AlphabetPuzzle::displayPuzzle() {
    
    //Open the font
    gFont = TTF_OpenFont( "AmaticSC-Regular.ttf", 28 );
    if( gFont == NULL )
    {
        printf( "Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError() );
        success = false;
    }
    else
    {
        //Render text
        SDL_Color textColor = { 0, 0, 0 };
        if( !gTextTexture.loadFromRenderedText( "Hey! I'm the gate-keeper of Math Town and if you want to leave the town you have to be able to solve this puzzle. You have three tries to solve this puzzle!\nAre you ready? Here goes!", textColor ) )
        {
            printf( "Failed to render text texture!\n" );
            success = false;
        }
    }

    //SDL code for displaying puzzle image - TODO
    
}

int AlphabetPuzzle::playPuzzle() { //returns the amount of points player should get
    int correct = 6;
    int answer;
    int tryNumber = 1;
    int i;
    
    for ( tryNumber=1; i<=3; i++ ) {
        cout << "What is your answer?" << endl;
        cout << "Answer: ";
        cin >> answer;
        
        if ( answer == correct ) { //user's answer matches the correct answer
            cout << "Congratulations! You got it correct!" << endl;
            
            if ( tryNumber == 1 ) { //got the answer on the first try
                cout << "You got it correct on your first try, so you can leave the town for free!" << endl;
                return points;
            } else if ( tryNumber == 2 ) { //got the answer on the second try
                cout << "You got it correct but on your second try, but I got hungry waiting for you to solve it so give me some of your food!" << endl;
                cout << "Oh no! You are forced to share 30 points worth of ingredients from your bag." << endl;
                points+=30;
                return points;
            } else if ( tryNumber == 3 ) { //got the answer on the third try
                cout << "You got it correct but on your third try, but I got hungry waiting for you to solve it so give me some of your food!" << endl;
                cout << "Oh no! You are forced to share 60 points worth of ingredients from your bag." << endl;
                points+=60;
                return points;
            }
        }
    }
    //if player is unable to solve the puzzle in 3 tries,
    cout << "You're taking too long to come up with the correct answer! For wasting so much of my time give me something yummy!" << endl;
    cout << "Oh no! The gate-keeper ate 100 points worth of ingredients from your bag! At least you finally get to exit the Math Town." << endl;
    points+=100;
    return points;
    
    
}

bool AlphabetPuzzle::loadMedia()
{
    
    //Loading success flag
    bool success = true;
    
//    //Load sprite sheet texture
//    if( !gSpriteSheetTexture.loadFromFile( "numbers.png" ) )
//    {
//        printf( "Failed to load sprite sheet texture!\n" );
//        success = false;
//    }
//    else
//    {
//        //Make Sprite clips from spriteSheet
//        for(int i = 0; i < 10; i++)
//        {
//            gSpriteClips[i].x = startx + width*i + 4*i;
//            gSpriteClips[i].y = starty;
//            gSpriteClips[i].w = width;
//            gSpriteClips[i].h = height;
//        }
//    }
    
    if( !gBackgroundTexture.loadFromFile( "sudoku_background.png" ))
    {
        printf( "Failed to load sprite sheet texture!\n" );
        success = false;
    }
    
    if( !(gSelectorTexture.loadFromFile("selector.png")))
    {
        printf("Failed to load selector\n");
        success = false;
    }
    
    return success;
}

