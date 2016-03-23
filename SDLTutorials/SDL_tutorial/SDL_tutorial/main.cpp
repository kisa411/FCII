/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
 and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL2/SDL.h> //mandatory to include for all SDL/SDL2 programs
#include <stdio.h>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main( int argc, char* args[] ) //mandatory for all SDL/SDL2 programs
{
    //The window we'll be rendering to
    SDL_Window* window = NULL;
    
    //The surface contained by the window
    SDL_Surface* screenSurface = NULL;
    
    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() ); //SDL_GetError() returns the latest error produced by an SDL function
    }
    else
    {
        //Create window
        window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN ); //WINDOWPOS_UNDEFINED (x, y) coordinates of where the window should be created, but since we don't care it's undefined; SDL_WINDOW_SHOWN makes sure the created window is shown
        if( window == NULL ) //if there was an error in creating the window SDL_CreateWindow() returns NULL
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() ); //print out the error so we know what happened
        }
        else
        {
            //Get window surface
            screenSurface = SDL_GetWindowSurface( window ); //get the surface so that we can draw on it
            
            //Fill the surface white
            SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) ); //draw something to the window
            
            //Update the surface
            SDL_UpdateWindowSurface( window ); //kind of like gfx_flush(), make sure the stuff drawn onto the window is shown
            
            //Wait two seconds
            SDL_Delay( 2000 ); //time parameter is in milliseconds
        }
    }
    
    //Destroy window
    SDL_DestroyWindow( window ); //free up memory by destroying window and surface
    
    //Quit SDL subsystems
    SDL_Quit();
    
    return 0;
}



