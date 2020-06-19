//
//  Board.h
//  Tetris
//
//  Created by Andrés Caballero Toledo on 17/06/2020.
//  Copyright © 2020 act. All rights reserved.
//

#ifndef BOARD_H
#define BOARD_H

#define BOARD_ROWS 20
#define BOARD_COLUMNS 10
#define HALF_SECOND 500

#include "Tile.h"
#include "Timer.h"

#include <string>

// Tiles identifiers
enum GameTiles {
    BLUE,
    GREEN,
    ORANGE,
    RED,
    VIOLET,
    YELLOW,
    TOTAL_TILES
};

// Game board
extern int board[BOARD_ROWS][BOARD_COLUMNS];
// SDL_Textures from the images
extern Tile tiles[TOTAL_TILES];

// Load the textures needed
bool loadTextures();

// Initialize board
void initializeBoard();

// Draw board
void drawBoard();

// Piece drawer
void drawTile(int *x, int *y, int *type, Timer *timer, int *seconds);

#endif
