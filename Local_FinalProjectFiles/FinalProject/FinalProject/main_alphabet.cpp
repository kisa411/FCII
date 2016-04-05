//
//  main.cpp
//  FinalProject
//
//  Created by Emily Koh on 4/3/16.
//  Copyright © 2016 Emily Koh. All rights reserved.
//

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <sstream>
#include "alphabetPuzzle.h"
#include "SDL.h"
#include "texture.hpp"

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

// Initialize SDL_ttf library
if (TTF_Init() != 0)
{
    cerr << "TTF_Init() Failed: " << TTF_GetError() << endl;
    SDL_Quit();
    exit(1);
    }
    
    // Load a font
    TTF_Font *font;
    font = TTF_OpenFont("AmaticSC-Regular.ttf", 18);
    if (font == NULL)
    {
        cerr << "TTF_OpenFont() Failed: " << TTF_GetError() << endl;
        TTF_Quit();
        SDL_Quit();
        exit(1);
    }
    
    // Write text to surface
    SDL_Surface *text;
    SDL_Color text_color = {255, 255, 255};
    text = TTF_RenderText_Solid(font,
                                "A journey of a thousand miles begins with a single step.",
                                text_color);
    
    if (text == NULL)
    {
        cerr << "TTF_RenderText_Solid() Failed: " << TTF_GetError() << endl;
        TTF_Quit();
        SDL_Quit();
        exit(1);
    }

int main( int argc, char* args[] )
{
    AlphabetPuzzle object;
    //Start up SDL and create window
    if( !object.init() )
    {
        printf( "Failed to initialize!\n" );
    }
    else
    {
        //Load media
        if( !object.loadMedia( "alphabetpuzzle.png") )
        {
            printf( "Failed to load media!\n" );
        }
        else
        {
            //Main loop flag
            bool quit = false;
            
            //Event handler
            SDL_Event e;
            
            //While application is running
            while( !quit )
            {
                //Handle events on queue
                while( SDL_PollEvent( &e ) != 0 )
                {
                    //User requests quit
                    if( e.type == SDL_QUIT )
                    {
                        quit = true;
                    }
                }
                //Apply the image stretched, then apply the PNG image
                SDL_Rect stretchRect;
                stretchRect.x = 0;
                stretchRect.y = 0;
                stretchRect.w = SCREEN_WIDTH;
                stretchRect.h = SCREEN_HEIGHT;
                SDL_BlitScaled( gPNGSurface, NULL, gScreenSurface, &stretchRect ); //update the size of the picture so that it fits on the window screen
                
                //Update the surface
                SDL_UpdateWindowSurface( gWindow );
                object.displayPuzzle();
            }
        }
    }
    
    //Free resources and close SDL
    object.close();
    
    return 0;
}