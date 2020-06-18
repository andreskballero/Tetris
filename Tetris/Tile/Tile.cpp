//
//  Tile.cpp
//  Tetris
//
//  Created by Andrés Caballero Toledo on 17/06/2020.
//  Copyright © 2020 act. All rights reserved.
//

#include "Tile.h"

Tile::Tile() {
    mTexture = NULL;
    mWidth = 0;
    mHeight = 0;
}


Tile::~Tile() {
    free();
}


bool Tile::loadFromFile(std::string path) {
    // Get rid of the preexisting texture
    free();
    
    // Load image at specified path
    SDL_Surface *loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == NULL) {
        printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
    } else {
        SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0x00, 0xFF, 0xFF));
        // Create texture from surface pixels
        mTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
        if (mTexture == NULL) {
            printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
        } else {
            // Get image dimensions
            mWidth = SCREEN_WIDTH / 10; //loadedSurface->w;
            mHeight = SCREEN_HEIGHT / 20; //loadedSurface->h;
        }
        // Get rid of the old loaded surface
        SDL_FreeSurface(loadedSurface);
    }
    
    return mTexture != NULL;
}


bool Tile::loadFromRenderedText(std::string textureText, SDL_Color textColor) {
    free();
    
    // Render text surface
    SDL_Surface *textSurface = TTF_RenderText_Solid(gFont, textureText.c_str(), textColor);
    if (textSurface != NULL) {
        mTexture = SDL_CreateTextureFromSurface(gRenderer, textSurface);
        if (mTexture == NULL) {
            printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
        } else {
            mWidth = textSurface->w;
            mHeight = textSurface->h;
        }
        SDL_FreeSurface(textSurface);
    } else {
        printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
    }
    
    return mTexture != NULL;
}


void Tile::render(const int x, const int y, SDL_Rect *clip, float angle, SDL_Point *center, SDL_RendererFlip flip) {
    // Set rendering space and render to screen
    SDL_Rect renderQuad = {x, y, mWidth, mHeight};
    
    // Set clip rendering dimensions
    if (clip != NULL) {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }
    
    // Render to screen
    SDL_RenderCopyEx(gRenderer, mTexture, clip, &renderQuad, angle, center, flip);
}


void Tile::free() {
    if (mTexture != NULL) {
        SDL_DestroyTexture(mTexture);
        mTexture = NULL;
        mWidth = 0;
        mHeight = 0;
    }
}


void Tile::setColor(Uint8 red, Uint8 green, Uint8 blue) {
    SDL_SetTextureColorMod(mTexture, red, green, blue);
}


void Tile::setBlendMode(SDL_BlendMode blending) {
    SDL_SetTextureBlendMode(mTexture, blending);
}


void Tile::setAlpha(Uint8 alpha) {
    SDL_SetTextureAlphaMod(mTexture, alpha);
}


int Tile::getWidth() {
    return mWidth;
}


int Tile::getHeight() {
    return mHeight;
}
