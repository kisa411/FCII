//
//  alphabetPuzzle.cpp
//  alphabetPuzzle
//
//  Created by Emily Koh on 4/9/16.
//  Copyright © 2016 Emily Koh. All rights reserved.
//

#include "alphabetPuzzle.hpp"

//Using SDL, SDL_image, SDL_ttf, standard IO, strings, and string streams
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <iostream>
#include <sstream>
#include "sdl_win_wrap.hpp"
#include "texture.hpp"

using namespace std;



AlphabetPuzzle::AlphabetPuzzle( SDL_Window* gWindow, SDL_Renderer* gRenderer ) : gTextTexture(gWindow, gRenderer), gBackgroundTexture(gWindow, gRenderer), gInputTextTexture(gWindow, gRenderer), gPromptTextTexture(gWindow, gRenderer) { //default constructor - member initialization syntax to initialize LTexture
    points = 0; //set initial value of points to be 100
}


void AlphabetPuzzle::displayPuzzle() {
    
    SDL_GetWindowSize(gWindow, &SCREEN_WIDTH, &SCREEN_HEIGHT); //store the window dimensions
    
    bool success =  true;
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
    
    //SDL code for displaying puzzle image
    gBackgroundTexture.render(0, 0, NULL);
    
}

int AlphabetPuzzle::playPuzzle() { //returns the amount of points player should get
    int correct = 6;
    int tryNumber = 1;
    int i;
    
    for ( i=1; i<=3; i++ ) {
        //Render text
        SDL_Color textColor = { 0, 0, 0 };
        if( !gTextTexture.loadFromRenderedText( "What is your answer?\n", textColor ) ) {
            printf( "Failed to render text texture!\n" );
        }
        
        //Main loop flag
        bool quit = false;
        
        //Event handler
        SDL_Event e;

        //Enable text input
        SDL_StartTextInput();
        
        //The current input text.
        std::string inputText = "Answer: ";
        gTextTexture.loadFromRenderedText( inputText.c_str(), textColor );

        
        //While application is running
        while( !quit ) {
            //The rerender text flag
            bool renderText = false;
            
            //Handle events on queue
            while( SDL_PollEvent( &e ) != 0 ) {
                //User requests quit
                if( e.type == SDL_QUIT ) {
                    quit = true;
                }//Special key input
                else if( e.type == SDL_KEYDOWN ){
                    //Handle backspace
                    if( e.key.keysym.sym == SDLK_BACKSPACE && inputText.length() > 0 ){
                        //lop off character
                        inputText.pop_back();
                        renderText = true;
                    }
                }//Special text input event
                else if( e.type == SDL_TEXTINPUT )
                {
                    //Not copy or pasting
                    if( !( ( e.text.text[ 0 ] == 'c' || e.text.text[ 0 ] == 'C' ) && ( e.text.text[ 0 ] == 'v' || e.text.text[ 0 ] == 'V' ) && SDL_GetModState() & KMOD_CTRL ) ){
                        //Append character
                        inputText += e.text.text;
                        renderText = true;
                    }
                }
            }
            
            //Rerender text if needed
            if( renderText ){
                //Text is not empty
                if( inputText != "" ){
                    //Render new text
                    gInputTextTexture.loadFromRenderedText( inputText.c_str(), textColor );
                }
                //Text is empty
                else{
                    //Render space texture
                    gInputTextTexture.loadFromRenderedText( " ", textColor );
                }
            }
            
            //Clear screen
            SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
            SDL_RenderClear( gRenderer );
            
            //Render text textures
            gPromptTextTexture.render( ( SCREEN_WIDTH - gPromptTextTexture.getWidth() ) / 2, 0 );
            gInputTextTexture.render( ( SCREEN_WIDTH - gInputTextTexture.getWidth() ) / 2, gPromptTextTexture.getHeight() );
            
            //Update screen
            SDL_RenderPresent( gRenderer );
        }
        
        
        //Disable text input
        SDL_StopTextInput();
        
        int number = stoi(inputText);
    
        if ( number == 6) { //user's answer matches the correct answer
            if( !gTextTexture.loadFromRenderedText( "Congratulations! You got it correct!\n  ", textColor ) ) {
                printf( "Failed to render text texture!\n" );
            }
            if ( tryNumber == 1 ) { //got the answer on the first try
                if( !gTextTexture.loadFromRenderedText( "The gatekeeper says: You got it correct on your first try, so you can leave the town for free!\n  ", textColor ) ) {
                    printf( "Failed to render text texture!\n" );
                }
                return points;
            } else if ( tryNumber == 2 ) { //got the answer on the second try
                if( !gTextTexture.loadFromRenderedText( "The gatekeeper says: You got it correct but on your second try, but I got hungry waiting for you to solve it so give me some of your food!\n Oh no! You are forced to share 30 points worth of ingredients from your bag.\n ", textColor ) ) {
                    printf( "Failed to render text texture!\n" );
                }
                points+=30;
                return points;
            } else if ( tryNumber == 3 ) { //got the answer on the third try
                if( !gTextTexture.loadFromRenderedText( "The gatekeeper says: You got it correct but on your third try, but I got hungry waiting for you to solve it so give me some of your food!\n Oh no! You are forced to share 60 points worth of ingredients from your bag.\n ", textColor ) ) {
                    printf( "Failed to render text texture!\n" );
                }
                points+=60;
                return points;
            }
        }
    }
    
    
    SDL_Color textColor = { 0, 0, 0 };
    //if player is unable to solve the puzzle in 3 tries,
    if( !gTextTexture.loadFromRenderedText( "The gatekeeper says: You're taking too long to come up with the correct answer! For wasting so much of my time give me something yummy!\n Oh no! The gate-keeper ate 100 points worth of ingredients from your bag! At least you finally get to exit the Math Town.\n", textColor ) ) {
        printf( "Failed to render text texture!\n" );
    }
    
    points+=100;
    return points;

    
}


bool AlphabetPuzzle::loadMedia() {
    
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
