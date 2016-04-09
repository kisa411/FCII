//
//  sdl_win_wrap.hpp
//  blackjack
//
//  Created by Emily Koh on 4/9/16.
//  Copyright © 2016 Emily Koh. All rights reserved.
//

#ifndef sdl_win_wrap_hpp
#define sdl_win_wrap_hpp

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <iostream>


class SDL_Win_Wrap
{
public:
    SDL_Win_Wrap(int nScreenWidth = 640, int nScreenHeight = 480);
    ~SDL_Win_Wrap();
    int getScreenWidth();
    int getScreenHeight();
    const int SCREEN_WIDTH;
    const int SCREEN_HEIGHT;
    bool init(); //Starts up SDL and creates window
    void close(); //Frees media and shuts down SDL
    SDL_Window* getWindow();
    SDL_Renderer* getRenderer();
    //The window we'll be rendering to
    SDL_Window* gWindow ;
    
    //The window renderer
    SDL_Renderer* gRenderer;
};


#endif /* sdl_win_wrap_hpp */
