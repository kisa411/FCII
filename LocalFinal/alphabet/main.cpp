//
//  main.cpp
//  FinalProject
//
//  Created by Emily Koh on 4/3/16.
//  Copyright © 2016 Emily Koh. All rights reserved.
//

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <sstream>
#include "alphabetPuzzle.h"
#include "texture.h"
#include "sdl_win_wrap.h"
using namespace std;

int main () {
    SDL_Win_Wrap window_instance; //SDL window object
    AlphabetPuzzle puzzle( window_instance.getWindow(), window_instance.getRenderer() ); //AlphabetPuzzle object
    for ( int i=0; i<3000; i++ ) {
    	puzzle.displayTown();
    }

    puzzle.playPuzzle();
}