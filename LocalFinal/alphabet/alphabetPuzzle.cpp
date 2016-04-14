//
//  alphabetPuzzle.cpp
//  alphabetPuzzle
//
//  Created by Emily Koh on 4/9/16.
//  Copyright © 2016 Emily Koh. All rights reserved.
//

#include "alphabetPuzzle.h"

//Using SDL, SDL_image, SDL_ttf, standard IO, strings, and string streams
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <iostream>
#include <sstream>
#include "sdl_win_wrap.h"
#include "texture.h"

using namespace std;


AlphabetPuzzle::AlphabetPuzzle( SDL_Window* ngWindow, SDL_Renderer* ngRenderer ) : gTextTexture(ngWindow, ngRenderer), gBackgroundTexture(ngWindow, ngRenderer), gPuzzleTexture(ngWindow, ngRenderer), gInputTextTexture(ngWindow, ngRenderer), gPromptTextTexture(ngWindow, ngRenderer), gWindow(ngWindow), gRenderer(ngRenderer) { //default constructor - member initialization syntax to initialize LTexture
    points = 0; //set initial value of points to be 0
    complete = false;
    loadMedia();
    SDL_GetWindowSize(gWindow, &SCREEN_WIDTH, &SCREEN_HEIGHT); //store the window dimensions
}

AlphabetPuzzle::~AlphabetPuzzle() { //free up all the allocated memory for the textures
    gBackgroundTexture.free(); 
    gTextTexture.free();
    gInputTextTexture.free();
    gPromptTextTexture.free();
}

void AlphabetPuzzle::displayTown() {
    
    int textXpos = SCREEN_WIDTH/5;
    int textYpos = (3*SCREEN_HEIGHT)/4;

    bool success = true;

    SDL_RenderClear( gRenderer );
    //SDL code for displaying (rendering) puzzle image
    gBackgroundTexture.render(0,0, SCREEN_WIDTH, SCREEN_HEIGHT, NULL);

    //Open the font
    //Free global font
    TTF_CloseFont( gFont );
    gFont = TTF_OpenFont( "adamwarrenpro.ttf", 18 );
    if( gFont == NULL )
    {
        printf( "Failed to load font! SDL_ttf Error: %s\n", TTF_GetError() );
        success = false;
    }
    else
    {
        //Render text
        SDL_Color textColor = { 0, 0, 0 };
        gTextTexture.setFont(gFont);
        if( !gTextTexture.loadFromRenderedTextWrapped( "Hey! I'm the gate-keeper of Math Town and in order to leave you need to solve this puzzle. You only get three tries, so good luck!\n", textColor, 400 ) )
        {
            printf( "Failed to render text texture!\n" );
            success = false;
        }
        gTextTexture.render(textXpos, textYpos);

    }


    // Update Screen
    SDL_RenderPresent( gRenderer );
 
}

int AlphabetPuzzle::displayPuzzle() { //return amount of points player should get
    string answer;
    bool correct = false;
    int tryNumber=0;
    int textXpos = SCREEN_WIDTH/5;
    int textYpos = (3*SCREEN_HEIGHT)/4;

    //Loading success flag
    bool success = true;
        
    //Event handler
    SDL_Event e;

    SDL_Color textColor = { 0, 0, 0 };

    TTF_CloseFont( gFont );
    gFont = TTF_OpenFont( "adamwarrenpro.ttf", 18 );
    if( gFont == NULL )
    {
        printf( "Failed to load font! SDL_ttf Error: %s\n", TTF_GetError() );
        success = false;
    }
    gTextTexture.setFont(gFont);

    while (correct==false) {
        tryNumber++;
        answer = userInput(); //returns user's input
        correct = validate(answer); //returns whether or not the input is right
        if (correct==true) {
            if( !gTextTexture.loadFromRenderedTextWrapped( "Congratulations! You got it correct!\n  ", textColor, 350 ) ) {
                printf( "Failed to render text texture!\n" );
            }
            gTextTexture.render(textXpos, textYpos);
            if ( tryNumber == 1 ) { //got the answer on the first try
                handleEvent( e, tryNumber );
                return points;
            } else if ( tryNumber == 2 ) { //got the answer on the second try
                handleEvent( e, tryNumber );
                points-=30;
                return points;
            } else if ( tryNumber == 3 ) { //got the answer on the third try
                handleEvent( e, tryNumber );
                points-=60;
                return points;
            } else { //if player is unable to solve the puzzle in 3 tries
                handleEvent( e, tryNumber );
                points-=100;
                return points;
            }

        } else if (correct==false) {
            if( !gTextTexture.loadFromRenderedTextWrapped( "That's wrong, try again.\n  ", textColor, 350 ) ) {
                printf( "Failed to render text texture!\n" );
            }
            gTextTexture.render(textXpos, textYpos);
        }

    }

}

int AlphabetPuzzle::playPuzzle() {

    int endPoints;

    while (complete==false) {
        SDL_RenderClear( gRenderer );
        //SDL code for displaying (rendering) puzzle image
        gPuzzleTexture.render(0,0, SCREEN_WIDTH, SCREEN_HEIGHT, NULL);
        endPoints = displayPuzzle(); //display the main background
        // endPoints = userInput(); //check for user input
        // Update Screen
        SDL_RenderPresent( gRenderer );
    }

    return endPoints;

}

bool AlphabetPuzzle::handleEvent( SDL_Event &e, int tryNumber ) {

    //Loading success flag
    bool success = true;

    int textXpos = SCREEN_WIDTH/5;
    int textYpos = (3*SCREEN_HEIGHT)/4;

    SDL_Color textColor = { 0, 0, 0 };
    TTF_CloseFont( gFont );
    gFont = TTF_OpenFont( "adamwarrenpro.ttf", 18 );
    if( gFont == NULL )
    {
        printf( "Failed to load font! SDL_ttf Error: %s\n", TTF_GetError() );
        success = false;
    }
    else
    {
        //Render text
        SDL_Color textColor = { 0, 0, 0 };
        gTextTexture.setFont(gFont);
    }

    while(SDL_PollEvent(&e)) { //if events exist in the queue
        //if user exits out of window
        if(e.type == SDL_QUIT)
        {
            complete = true;
        }//If mouse event happened
        else if ( e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP )
        {
            SDL_RenderClear( gRenderer ); //clear renderer 
            //Actions depending on mouse click down or up (relese)
            switch( e.type )
            {
                case SDL_MOUSEBUTTONDOWN:
                    if (tryNumber==1) { //load text for first try
                        if( !gTextTexture.loadFromRenderedTextWrapped( "The gatekeeper says: You got it correct on your first try, so you can leave the town for free!\n  ", textColor, 350 ) ) {
                            printf( "Failed to render text texture!\n" );
                        }
                        gTextTexture.render(textXpos, textYpos);
                        complete = true;
                        break;
                    } else if (tryNumber==2) { //load text for second try
                        if( !gTextTexture.loadFromRenderedTextWrapped( "The gatekeeper says: You got it correct but on your second try, but I got hungry waiting for you to solve it so give me some of your food!\n Oh no! You are forced to share 30 points worth of ingredients from your bag.\n ", textColor, 350 ) ) {
                            printf( "Failed to render text texture!\n" );
                        }
                        gTextTexture.render(textXpos, textYpos);
                        complete = true;
                        return complete;
                        break;
                    } else if (tryNumber==3) { //load text for third try
                        if( !gTextTexture.loadFromRenderedTextWrapped( "The gatekeeper says: You got it correct but on your third try, but I got hungry waiting for you to solve it so give me some of your food!\n Oh no! You are forced to share 60 points worth of ingredients from your bag.\n ", textColor, 350 ) ) {
                            printf( "Failed to render text texture!\n" );
                        }
                        gTextTexture.render(textXpos, textYpos);
                        complete = true;
                        return complete;
                        break;
                    } else { //load text for failed attempt
                        if( !gTextTexture.loadFromRenderedTextWrapped( "The gatekeeper says: You're taking too long to come up with the correct answer! For wasting so much of my time give me something yummy!\n Oh no! The gate-keeper ate 100 points worth of ingredients from your bag! At least you finally get to exit the Math Town.\n", textColor, 350 ) ) {
                            printf( "Failed to render text texture!\n" );
                        }
                        gTextTexture.render(textXpos, textYpos);
                        complete = true;
                        return complete;
                        break;
                    }
                    break;
                
                case SDL_MOUSEBUTTONUP: //don't do anything if mouse is released
                    break;
            }
        }
    }
    return complete;
}

bool AlphabetPuzzle::loadMedia() {
    
    //Loading success flag
    bool success = true;
    
    //Open the background picture
    if( !gBackgroundTexture.loadFromFile( "alphabet.png" ))
    {
        printf( "Failed to load background texture!\n" );
        success = false;
    }

    //Open puzzle picture
    if( !gPuzzleTexture.loadFromFile( "alphabetpuzzle.png" ))
    {
        printf( "Failed to load background texture!\n" );
        success = false;
    }
    
    //Open the font
    gFont = TTF_OpenFont( "adamwarrenpro.ttf", 18 );
    if( gFont == NULL )
    {
        printf( "Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError() );
        success = false;
    }
    else
    {
        //Render the prompt
        SDL_Color textColor = { 0, 0, 0, 0xFF };
        gPromptTextTexture.setFont(gFont);
        if( !gPromptTextTexture.loadFromRenderedTextWrapped( "What is your answer?", textColor, 350 ) )
        {
            printf( "Failed to render prompt text!\n" );
            success = false;
        }
    }
    
    
    return success;
}

string AlphabetPuzzle::userInput() {

    int textXpos = (2*SCREEN_WIDTH)/5;
    int textYpos = (3*SCREEN_HEIGHT)/4;

    //Main loop flag
    bool quit = false;
    bool success = true;

    //Event handler
    SDL_Event e;

    //Set text color as black
    SDL_Color textColor = { 0, 0, 0, 0xFF };

    //Open the font
    gFont = TTF_OpenFont( "adamwarrenpro.ttf", 18 );
    if( gFont == NULL )
    {
        printf( "Failed to load adamwarrenpro font! SDL_ttf Error: %s\n", TTF_GetError() );
        success = false;
    }

    //render the question 
    gPromptTextTexture.setFont(gFont);
    gPromptTextTexture.render(textXpos, textYpos); 
    
    //The current input text.
    string inputText = "Put answer here";
    gInputTextTexture.setFont(gFont);
    gInputTextTexture.loadFromRenderedText( inputText.c_str(), textColor );

    //Enable text input
    SDL_StartTextInput();

    //While application is running
    while( !quit )
    {
        //The rerender text flag
        bool renderText = false;

        //Handle events on queue
        while( SDL_PollEvent( &e ) != 0 )
        {
            //User requests quit
            if( e.type == SDL_QUIT )
            {
                quit = true;
            }
            //Special key input
            else if( e.type == SDL_KEYDOWN )
            {
                //Handle backspace
                if( e.key.keysym.sym == SDLK_BACKSPACE && inputText.length() > 0 )
                {
                    //lop off character
                    inputText.pop_back();
                    renderText = true;
                }
            }
            //Special text input event
            else if( e.type == SDL_TEXTINPUT )
            {
                //Not copy or pasting
                if( !( ( e.text.text[ 0 ] == 'c' || e.text.text[ 0 ] == 'C' ) && ( e.text.text[ 0 ] == 'v' || e.text.text[ 0 ] == 'V' ) && SDL_GetModState() & KMOD_CTRL ) )
                {
                    //Append character
                    inputText += e.text.text;
                    renderText = true;
                }
            }
        }

        //Rerender text if needed
        if( renderText )
        {
            //Text is not empty
            if( inputText != "" )
            {
                //Render new text
                gInputTextTexture.loadFromRenderedText( inputText.c_str(), textColor );
            }
            //Text is empty
            else
            {
                //Render space texture
                gInputTextTexture.loadFromRenderedText( " ", textColor );
            }
        }

        //Clear screen
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
        SDL_RenderClear( gRenderer );

        //Render text textures
        gPromptTextTexture.render(textXpos, textYpos);
        gInputTextTexture.render(textXpos, textYpos+gPromptTextTexture.getHeight());

        //Update screen
        SDL_RenderPresent( gRenderer );
    }
    
    //Disable text input
    SDL_StopTextInput();

    return inputText;
}


bool AlphabetPuzzle::validate( string userInput ) { //determines whether user input is correct or not
    bool correct = false;

    int answer = 6;
    int number = std::stoi(userInput);

    if (number==answer) {
        correct = true;
        return correct;
    }
    
    return correct;

}

