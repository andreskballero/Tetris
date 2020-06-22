//
//  Board.h
//  Tetris
//
//  Created by Andrés Caballero Toledo on 17/06/2020.
//  Copyright © 2020 act. All rights reserved.
//

#ifndef BOARD_H
#define BOARD_H


#include "Common.h"
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

enum GamePieces {
    L,
    LINVERSE,
    Z,
    ZINVERSE,
    T,
    I,
    SQUARE
};

// Game board
extern int board[BOARD_ROWS][BOARD_COLUMNS];
// SDL_Textures from the images
extern Tile tiles[TOTAL_TILES];
// 4x4 arrays to hold the pieces
extern int pieces[TOTAL_PIECES][PIECE_SIDE][PIECE_SIDE][ROTATIONS];

// Load the textures needed
bool loadTextures();

// Initialize the pieces
void initializePieces();

// Initialize board
void initializeBoard();

// Draw board
void drawBoard();

// Update the board to draw the new piece
void updateBoard(const int x, const int y, const int shape, const int rotation);

// Piece drawer
void drawPiece(const int x, const int y, const int shape, const int rotation);

// Collision checker
bool checkCollision(int *x, int *y, int *shape, int *rotation, Timer *timer, int *seconds, const int acceleration);

// Line checker in charge of erasing the completed lines
bool checkLine();

// Column updater that is executed if one or more lines are erased
void updateColumns();

// Returns true if the future position is valid for placing the piece
bool tentativePosition(const int x, const int y, const int shape, const int rotation);

// Calculates the piece width
int calculatePieceWidth(const int shape, const int rotation);

#endif
