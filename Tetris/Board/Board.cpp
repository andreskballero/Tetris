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

// Set the whole board to -1 (empty position)
void initializeBoard() {
    for (int y = 0; y < BOARD_ROWS; ++y) {
        for (int x = 0; x < BOARD_COLUMNS; ++x) {
            board[y][x] = -1;
        }
    }
}


// Run the whole board and draw in the positions where
// the board is different than -1
void drawBoard() {
    for (int y = 0; y < BOARD_ROWS; ++y) {
        for (int x = 0; x < BOARD_COLUMNS; ++x) {
            if (board[y][x] != -1) {
                int type = board[y][x];
                tiles[type].render((SCREEN_WIDTH / BOARD_COLUMNS) * x, (SCREEN_HEIGHT / BOARD_ROWS) * y);
            }
            //printf("%d ", board[y][x]);
        }
        //printf("\n");
    }
    //printf("\n\n");
}


// Draw the current active tile
void drawTile(int *x, int *y, int *type, Timer *timer, int *seconds) {
    // Render the tile in the current position
    tiles[*type].render((SCREEN_WIDTH / BOARD_COLUMNS) * (*x), (SCREEN_HEIGHT / BOARD_ROWS) * (*y));
    //  Wait half a second
    if ((*timer).getTicks() - *seconds >= HALF_SECOND)
    {
        // If the tile has a tile underneath it or it is equal to the last row
        // of the board, modify the board to make it stay in place
        if (((*y < BOARD_ROWS - 1) && (board[(*y) + 1][*x] != -1)) || (*y == BOARD_ROWS-1)) {
            board[*y][*x] = *type;
            *x = rand() % BOARD_COLUMNS;
            *y = 0;
            *type = rand() % TOTAL_TILES;
        } else {
            // Reset second counter and increment y for the next iteration
            *seconds = (*timer).getTicks();
            ++(*y);
        }
    }
}


// Checks if there are lines that can be erased
bool checkLine() {
    bool erase = false;
    bool found = true;
    
    // Run the board rows and check if there is at least one -1
    // in a row; if there is a -1, that means the line is not full
    // and that a full line has not been found yet
    for (int y = 0; y < BOARD_ROWS; ++y) {
        for  (int x = 0; x < BOARD_COLUMNS; ++x) {
            if (board[y][x] == -1) {
                found = false;
                break;
            }
        }
        if (found) {
            // If a full line has been found, reset the whole line
            // to -1
            for (int x = 0; x < BOARD_COLUMNS; ++x) {
                board[y][x] = -1;
            }
            erase = true;
        } else {
            found = true;
        }
    }
    
    return erase;
}


// Updates the columns if there are lines that have been erased
void updateColumns() {
    bool update = true;
    
    // Runs the whole board starting from the bottom left
    for (int y = BOARD_ROWS - 1; y >= 0; --y) {
        for (int x = 0; x < BOARD_COLUMNS; ++x) {
            // If the whole line is -1, bring down the columns from
            // that line up
            if (board[y][x] != -1) {
                update = false;
                break;
            }
        }
        if (update) {
            for (int x = 0; x < BOARD_COLUMNS; ++x) {
                for (int z = y; z > 0; --z) {
                    board[z][x] = board[z - 1][x];
                }
            }
        } else {
            update = true;
        }
    }
}
