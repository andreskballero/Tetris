//
//  Board.cpp
//  Tetris
//
//  Created by Andrés Caballero Toledo on 17/06/2020.
//  Copyright © 2020 act. All rights reserved.
//

#include "Board.h"

int board[BOARD_ROWS][BOARD_COLUMNS];

Tile tiles[TOTAL_TILES];


bool loadTextures() {
    bool success = true;
    
    if (!tiles[BLUE].loadFromFile("../Assets/blue.png")) {
        printf("Could not load the blue texture.");
        success = false;
    }
    if (!tiles[GREEN].loadFromFile("../Assets/green.png")) {
        printf("Could not load the green texture.");
        success = false;
    }
    if (!tiles[ORANGE].loadFromFile("../Assets/orange.png")) {
        printf("Could not load the orange texture.");
        success = false;
    }
    if (!tiles[RED].loadFromFile("../Assets/red.png")) {
        printf("Could not load the red texture.");
        success = false;
    }
    if (!tiles[VIOLET].loadFromFile("../Assets/violet.png")) {
        printf("Could not load the violet texture.");
        success = false;
    }
    if (!tiles[YELLOW].loadFromFile("../Assets/yellow.png")) {
        printf("Could not load the yellow texture.");
        success = false;
    }
    
    return success;
}


void drawBoard() {
    for (int y = 0; y < BOARD_ROWS; ++y) {
        for (int x = 0; x < BOARD_COLUMNS; ++x) {
            if (board[y][x] != -1) {
                int type = board[y][x];
                tiles[type].render((SCREEN_WIDTH / BOARD_COLUMNS) * x, (SCREEN_HEIGHT / BOARD_ROWS) * y);
            }
        }
    }
}


void drawTile(int *x, int *y, int *type) {
    tiles[*type].render((SCREEN_WIDTH / BOARD_COLUMNS) * (*x), (SCREEN_HEIGHT / BOARD_ROWS) * (*y));
    ++(*y);
    
    if ((((*y) + 1) * BOARD_ROWS) * ASPECT_RATIO >= SCREEN_HEIGHT) {
        board[*y][*x] = *type;
        *x = rand() % BOARD_COLUMNS;
        *y = 0;
        *type = rand() % TOTAL_TILES;
    }
}
