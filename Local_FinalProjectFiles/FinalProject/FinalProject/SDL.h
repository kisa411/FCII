//
//  SDL.h
//  SDL_tutorial
//
//  Created by Emily Koh on 4/3/16.
//  Copyright © 2016 Emily Koh. All rights reserved.
//

#ifndef SDL_h
#define SDL_h

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <sstream>
#include "SDL.h"
#include <iostream>
using namespace std;

class SDL {

public:
    //Starts up SDL and creates window - function prototype
    bool init();

    //Loads media - function prototype
    bool loadMedia( string filename );

    //Frees media and shuts down SDL - function prototype
    void close();

};


#endif /* SDL_h */
