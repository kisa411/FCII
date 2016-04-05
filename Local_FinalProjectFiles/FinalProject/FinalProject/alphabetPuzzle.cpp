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
#include "SDL.h"

using namespace std;


AlphabetPuzzle::AlphabetPuzzle() { //default constructor
    points = 0; //set initial value of points to be 100
}

void AlphabetPuzzle::displayPuzzle() {
    
    cout << "Hey! I'm the gate-keeper of Math Town and if you want to leave the town you have to be able to solve this puzzle. You have three tries to solve this puzzle!\nAre you ready? Here goes!" << endl;
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


//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//The window we'll be rendering to - create pointer for window, but set to null for now
SDL_Window* gWindow = NULL;

//The surface contained by the window - create pointer for surface, but set to null for now
SDL_Surface* gScreenSurface = NULL;

//The image we will load and show on the screen - create pointer for surface, but set to null for now
SDL_Surface* gHelloWorld = NULL;

//Current displayed PNG image
SDL_Surface* gPNGSurface = NULL;

//Loads individual image
SDL_Surface* loadSurface( std::string path );

bool AlphabetPuzzle::init()
{
    
    //Initialization flag
    bool success = true;
    
    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        //Create window
        gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( gWindow == NULL )
        {
            printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            //Initialize PNG loading - create an image flag for the alphabet puzzle picture
            int imgFlags = IMG_INIT_PNG;
            if( !( IMG_Init( imgFlags ) & imgFlags ) )
            {
                printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
                success = false;
            }
            else
            {
                //Get window surface
                gScreenSurface = SDL_GetWindowSurface( gWindow );
            }
        }
    }
    
    return success;
    
}

bool AlphabetPuzzle::loadMedia( string filename ) //load picture
{
    //Loading success flag
    bool success = true;
    
    //Load PNG surface
    gPNGSurface = loadSurface( filename );
    if( gPNGSurface == NULL )
    {
        printf( "Failed to load PNG image!\n" );
        success = false;
    }
    
    return success;
}

void AlphabetPuzzle::close()
{
    //Free loaded image
    SDL_FreeSurface( gPNGSurface );
    gPNGSurface = NULL;
    
    //Destroy window
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;
    
    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}

SDL_Surface* loadSurface( std::string path )
{
    //The final optimized image
    SDL_Surface* optimizedSurface = NULL;
    
    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if( loadedSurface == NULL )
    {
        printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
    }
    else
    {
        //Convert surface to screen format
        optimizedSurface = SDL_ConvertSurface( loadedSurface, gScreenSurface->format, NULL );
        if( optimizedSurface == NULL )
        {
            printf( "Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
        }
        
        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }
    
    return optimizedSurface;
}
