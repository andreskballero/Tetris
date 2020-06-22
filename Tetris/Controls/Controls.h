//
//  Controls.h
//  Tetris
//
//  Created by Andrés Caballero Toledo on 21/06/2020.
//  Copyright © 2020 act. All rights reserved.
//

#ifndef CONTROLS_H
#define CONTROLS_H

#include "Common.h"

#include "SDL2/SDL.h"

void movePiece(SDL_Event *e, bool *quit, int *x, int *y, int *acceleration, const int shape);

#endif
