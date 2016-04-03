//
//  alphabetPuzzle.cpp
//
//  Created by Emily Koh on 3/20/16.
//  Copyright © 2016 Emily Koh. All rights reserved.
//

//Using SDL, SDL_image, SDL_ttf, standard IO, strings, and string streams
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <stdio.h>
#include <string>
#include <sstream>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Starts up SDL and creates window - function prototype
bool init();

//Loads media - function prototype
bool loadMedia();

//Frees media and shuts down SDL - function prototype
void close();

//The window we'll be rendering to - create pointer for window, but set to null for now
SDL_Window* gWindow = NULL;

//The surface contained by the window - create pointer for surface, but set to null for now
SDL_Surface* gScreenSurface = NULL;

//The image we will load and show on the screen - create pointer for surface, but set to null for now
SDL_Surface* gHelloWorld = NULL;

bool init()
{
    //Initialization flag - define variable
    bool success = true;
    
    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        //Create window
        gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( gWindow == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            //Get window surface
            gScreenSurface = SDL_GetWindowSurface( gWindow );
        }
    }
    
    return success;
}

bool loadMedia()
{
    //Loading success flag - define variable
    bool success = true;
    
    //Load splash image
    gHelloWorld = SDL_LoadBMP( "hello_world.bmp" );
    if( gHelloWorld == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", "hello_world.bmp", SDL_GetError() );
        success = false;
    }
    
    return success;
}

void close()
{
    //Deallocate surface
    SDL_FreeSurface( gHelloWorld );
    gHelloWorld = NULL;
    
    //Destroy window
    SDL_DestroyWindow( gWindow );
    gWindow = NULL; //make pointer point back to NULL after the thing it's pointing to has been destroyed
    
    //Quit SDL subsystems
    SDL_Quit();
}

int main( int argc, char* args[] ) //main function
{
    //Start up SDL and create window
    if( !init() )
    {
        printf( "Failed to initialize!\n" );
    }
    else
    {
        //Load media
        if( !loadMedia() )
        {
            printf( "Failed to load media!\n" );
        }
        else
        {
            //Apply the image
            SDL_BlitSurface( gHelloWorld, NULL, gScreenSurface, NULL );
            
            //Update the surface
            SDL_UpdateWindowSurface( gWindow );
            
            //Wait two seconds
            SDL_Delay( 2000 );
        }
    }
    
    //Free resources and close SDL
    close();
    
    return 0;
}