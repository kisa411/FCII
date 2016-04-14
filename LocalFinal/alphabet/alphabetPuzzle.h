//
//  alphabetPuzzle.hpp
//  alphabetPuzzle
//
//  Created by Emily Koh on 4/9/16.
//  Copyright © 2016 Emily Koh. All rights reserved.
//

#ifndef alphabetPuzzle_h
#define alphabetPuzzle_h

#include <iostream>
#include "texture.h"
using namespace std;

class AlphabetPuzzle {
    
public:
    AlphabetPuzzle( SDL_Window*, SDL_Renderer* ); //default constructor
    ~AlphabetPuzzle(); //destructor
    void displayTown(); //display the town
    int displayPuzzle(); //display the puzzle picture
    int playPuzzle(); //main driver function for alphabet puzzle
    
private:
    int points; //depending on how many tries it took player to get right answer, points value changes
    bool complete; //checks to see if user has solved puzzle or not

    //SDL member variables and helper functions
    LTexture gBackgroundTexture;
    LTexture gPuzzleTexture;
    LTexture gTextTexture;
    LTexture gInputTextTexture;
    LTexture gPromptTextTexture;
    
    //the window we'll be rendering to
    SDL_Window* gWindow;
    int SCREEN_WIDTH;
    int SCREEN_HEIGHT;
    
    SDL_Renderer* gRenderer;
    TTF_Font *gFont; //font to use
    
   
    bool handleEvent( SDL_Event& e, int tryNumber ); //Handles mouse event
    bool loadMedia(); //Loads necessary media
    string userInput(); //take in user input
    bool validate( string userInput ); //check user input against correct answer 

    
};


#endif
