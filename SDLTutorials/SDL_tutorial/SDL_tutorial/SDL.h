//
//  SDL.h
//  SDL_tutorial
//
//  Created by Emily Koh on 4/3/16.
//  Copyright © 2016 Emily Koh. All rights reserved.
//

#ifndef SDL_h
#define SDL_h

class SDL {


    //Starts up SDL and creates window - function prototype
    bool init();

    //Loads media - function prototype
    bool loadMedia();

    //Frees media and shuts down SDL - function prototype
    void close();

};


#endif /* SDL_h */
