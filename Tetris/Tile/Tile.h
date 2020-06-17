//
//  Tile.h
//  Tetris
//
//  Created by Andrés Caballero Toledo on 17/06/2020.
//  Copyright © 2020 act. All rights reserved.
//

#ifndef TILE_H
#define TILE_H

#include "SDLConfig.h"

#include "SDL2/SDL.h"
#include "SDL2_image/SDL_image.h"
#include "SDL2_ttf/SDL_ttf.h"

#include <string>

// Tile class - texture wrapper
class Tile {
public:
    Tile();
    ~Tile();
    
    bool loadFromFile(std::string path);
    bool loadFromRenderedText(std::string textureText, SDL_Color textColor);
    
    void render(const int x, const int y, SDL_Rect *clip = NULL, float angle = 0.0, SDL_Point *center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);
    
    void free();
    
    void setColor(Uint8 red, Uint8 green, Uint8 blue);
    void setBlendMode(SDL_BlendMode blending);
    void setAlpha(Uint8 alpha);
    
    int getWidth();
    int getHeight();
    
private:
    SDL_Texture *mTexture;
    
    int mWidth;
    int mHeight;
};

#endif
