//
//  SDLConfig.h
//  Tetris
//
//  Created by Andrés Caballero Toledo on 17/06/2020.
//  Copyright © 2020 act. All rights reserved.
//

#ifndef SDLCONFIG_H
#define SDLCONFIG_H

#include "../Common/Common.h"

#include "SDL2/SDL.h"
#include "SDL2_image/SDL_image.h"
#include "SDL2_ttf/SDL_ttf.h"

// The window we will be rendering to
SDL_Window *gWindow = NULL;

// The window renderer
SDL_Renderer *gRenderer = NULL;

// Globally used font
TTF_Font *gFont = NULL;

// Starts SDL and creates window
bool init();

// Loads media
bool loadMedia();

// Frees resources and quits SDL
void close();

#endif
