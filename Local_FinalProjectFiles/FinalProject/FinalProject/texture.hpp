//
//  texture.hpp
//  FinalProject
//
//  Created by Emily Koh on 4/3/16.
//  Copyright © 2016 Emily Koh. All rights reserved.
//

#ifndef texture_hpp
#define texture_hpp


#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

//Texture wrapper class
class LTexture
{
public:
    LTexture();  //Initializes variables
    ~LTexture(); //Deallocates memory
    bool loadFromFile( std::string path );  //Loads image at specified path
    
#ifdef _SDL_TTF_H
    //Creates image from font string
    bool loadFromRenderedText( std::string textureText, SDL_Color textColor );
#endif
    void free(); //Deallocates texture
    void setColor( Uint8 red, Uint8 green, Uint8 blue ); //Set color modulation
    void setBlendMode( SDL_BlendMode blending );  //Set blending
    void setAlpha( Uint8 alpha ); //Set alpha modulation
    void render( int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE );  //Renders texture at given point
    int getWidth(); //Gets image dimensions
    int getHeight(); //Gets image dimensions
    
private:
    SDL_Texture* mTexture;  //The actual hardware texture
    int mWidth; //Image dimensions
    int mHeight; //Image dimensions
};


#endif /* texture_hpp */
