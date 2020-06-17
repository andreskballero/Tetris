//
//  SDLConfig.h
//  Tetris
//
//  Created by Andrés Caballero Toledo on 17/06/2020.
//  Copyright © 2020 act. All rights reserved.
//

#ifndef SDLCONFIG_H
#define SDLCONFIG_H

#include "Common.h"

#include "SDL2/SDL.h"
#include "SDL2_image/SDL_image.h"
#include "SDL2_ttf/SDL_ttf.h"

// The window we will be rendering to
extern SDL_Window *gWindow;

// The window renderer
extern SDL_Renderer *gRenderer;

// Globally used font
extern TTF_Font *gFont;

// Starts SDL and creates window
bool init();

// Loads media
bool loadMedia();

// Frees resources and quits SDL
void close();

#endif
