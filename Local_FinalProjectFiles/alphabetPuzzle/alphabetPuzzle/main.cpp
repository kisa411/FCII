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
#include "alphabetPuzzle.hpp"
#include "sdl_win_wrap.hpp"
#include "texture.hpp"
using namespace std;

int main () {
    SDL_Win_Wrap window_instance; //SDL window object
    
    AlphabetPuzzle puzzle( window_instance.getWindow(), window_instance.getRenderer() ); //AlphabetPuzzle object
    puzzle.displayPuzzle();
    puzzle.playPuzzle();
}