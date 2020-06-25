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

int pieces[TOTAL_PIECES][PIECE_SIDE][PIECE_SIDE][ROTATIONS];


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


// Set the pieces to their initial values
void initializePieces() {
    // Initialize every piece array to -1
    for (int x = 0; x < TOTAL_PIECES; ++x) {
        for (int y = 0; y < PIECE_SIDE; ++y) {
            for (int z = 0; z < PIECE_SIDE; ++z) {
                for (int r = 0; r < ROTATIONS; ++r){
                    pieces[x][y][z][r] = -1;
                }
            }
        }
    }
    
    // L piece
    pieces[L][0][0][0] = BLUE;
    pieces[L][1][0][0] = BLUE;
    pieces[L][2][0][0] = BLUE;
    pieces[L][2][1][0] = BLUE;
    
    pieces[L][0][0][1] = BLUE;
    pieces[L][0][1][1] = BLUE;
    pieces[L][0][2][1] = BLUE;
    pieces[L][1][0][1] = BLUE;
    
    pieces[L][0][0][2] = BLUE;
    pieces[L][0][1][2] = BLUE;
    pieces[L][1][1][2] = BLUE;
    pieces[L][2][1][2] = BLUE;
    
    pieces[L][0][2][3] = BLUE;
    pieces[L][1][0][3] = BLUE;
    pieces[L][1][1][3] = BLUE;
    pieces[L][1][2][3] = BLUE;
    
    // Inverse L piece
    pieces[LINVERSE][0][1][0] = GREEN;
    pieces[LINVERSE][1][1][0] = GREEN;
    pieces[LINVERSE][2][1][0] = GREEN;
    pieces[LINVERSE][2][0][0] = GREEN;
    
    pieces[LINVERSE][0][0][1] = GREEN;
    pieces[LINVERSE][1][0][1] = GREEN;
    pieces[LINVERSE][1][1][1] = GREEN;
    pieces[LINVERSE][1][2][1] = GREEN;
    
    pieces[LINVERSE][0][0][2] = GREEN;
    pieces[LINVERSE][0][1][2] = GREEN;
    pieces[LINVERSE][1][0][2] = GREEN;
    pieces[LINVERSE][2][0][2] = GREEN;
    
    pieces[LINVERSE][0][0][3] = GREEN;
    pieces[LINVERSE][0][1][3] = GREEN;
    pieces[LINVERSE][0][2][3] = GREEN;
    pieces[LINVERSE][1][2][3] = GREEN;
    
    // Z piece
    pieces[Z][0][0][0] = ORANGE;
    pieces[Z][0][1][0] = ORANGE;
    pieces[Z][1][1][0] = ORANGE;
    pieces[Z][1][2][0] = ORANGE;
    
    pieces[Z][0][1][1] = ORANGE;
    pieces[Z][1][1][1] = ORANGE;
    pieces[Z][1][0][1] = ORANGE;
    pieces[Z][2][0][1] = ORANGE;
    
    pieces[Z][0][0][2] = ORANGE;
    pieces[Z][0][1][2] = ORANGE;
    pieces[Z][1][1][2] = ORANGE;
    pieces[Z][1][2][2] = ORANGE;
    
    pieces[Z][0][1][3] = ORANGE;
    pieces[Z][1][1][3] = ORANGE;
    pieces[Z][1][0][3] = ORANGE;
    pieces[Z][2][0][3] = ORANGE;
    
    // Inverse Z piece
    pieces[ZINVERSE][0][1][0] = RED;
    pieces[ZINVERSE][0][2][0] = RED;
    pieces[ZINVERSE][1][0][0] = RED;
    pieces[ZINVERSE][1][1][0] = RED;
    
    pieces[ZINVERSE][0][0][1] = RED;
    pieces[ZINVERSE][1][0][1] = RED;
    pieces[ZINVERSE][1][1][1] = RED;
    pieces[ZINVERSE][2][1][1] = RED;
    
    pieces[ZINVERSE][0][1][2] = RED;
    pieces[ZINVERSE][0][2][2] = RED;
    pieces[ZINVERSE][1][0][2] = RED;
    pieces[ZINVERSE][1][1][2] = RED;
    
    pieces[ZINVERSE][0][0][3] = RED;
    pieces[ZINVERSE][1][0][3] = RED;
    pieces[ZINVERSE][1][1][3] = RED;
    pieces[ZINVERSE][2][1][3] = RED;
    
    // T piece
    pieces[T][0][1][0] = VIOLET;
    pieces[T][1][0][0] = VIOLET;
    pieces[T][1][1][0] = VIOLET;
    pieces[T][1][2][0] = VIOLET;
    
    pieces[T][0][0][1] = VIOLET;
    pieces[T][1][0][1] = VIOLET;
    pieces[T][2][0][1] = VIOLET;
    pieces[T][1][1][1] = VIOLET;
    
    pieces[T][0][0][2] = VIOLET;
    pieces[T][0][1][2] = VIOLET;
    pieces[T][0][2][2] = VIOLET;
    pieces[T][1][1][2] = VIOLET;
    
    pieces[T][0][1][3] = VIOLET;
    pieces[T][1][1][3] = VIOLET;
    pieces[T][2][1][3] = VIOLET;
    pieces[T][1][0][3] = VIOLET;
    
    // I piece
    pieces[I][0][0][0] = YELLOW;
    pieces[I][1][0][0] = YELLOW;
    pieces[I][2][0][0] = YELLOW;
    pieces[I][3][0][0] = YELLOW;
    
    pieces[I][0][0][1] = YELLOW;
    pieces[I][0][1][1] = YELLOW;
    pieces[I][0][2][1] = YELLOW;
    pieces[I][0][3][1] = YELLOW;
    
    pieces[I][0][0][2] = YELLOW;
    pieces[I][1][0][2] = YELLOW;
    pieces[I][2][0][2] = YELLOW;
    pieces[I][3][0][2] = YELLOW;
    
    pieces[I][0][0][3] = YELLOW;
    pieces[I][0][1][3] = YELLOW;
    pieces[I][0][2][3] = YELLOW;
    pieces[I][0][3][3] = YELLOW;
    
    // Square piece
    pieces[SQUARE][0][0][0] = YELLOW;
    pieces[SQUARE][0][1][0] = YELLOW;
    pieces[SQUARE][1][0][0] = YELLOW;
    pieces[SQUARE][1][1][0] = YELLOW;
    
    pieces[SQUARE][0][0][1] = YELLOW;
    pieces[SQUARE][0][1][1] = YELLOW;
    pieces[SQUARE][1][0][1] = YELLOW;
    pieces[SQUARE][1][1][1] = YELLOW;
    
    pieces[SQUARE][0][0][2] = YELLOW;
    pieces[SQUARE][0][1][2] = YELLOW;
    pieces[SQUARE][1][0][2] = YELLOW;
    pieces[SQUARE][1][1][2] = YELLOW;
    
    pieces[SQUARE][0][0][3] = YELLOW;
    pieces[SQUARE][0][1][3] = YELLOW;
    pieces[SQUARE][1][0][3] = YELLOW;
    pieces[SQUARE][1][1][3] = YELLOW;
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


void updateBoard(const int x, const int y, const int shape, const int rotation) {
    // Update board (prolly in another function)
    for (int i = 0; i < PIECE_SIDE; ++i) {
        for (int j = 0; j < PIECE_SIDE; ++j) {
            if (pieces[shape][i][j][rotation] != -1) {
                board[y + i][x + j] = pieces[shape][i][j][rotation];
            }
        }
    }
}


void drawPiece(const int x, const int y, const int shape, const int rotation) {
    
    for (int i = 0; i < PIECE_SIDE; ++i) {
        for (int j = 0; j < PIECE_SIDE; j++) {
            if (pieces[shape][i][j][rotation] != -1) {
                int aux = pieces[shape][i][j][rotation];
                tiles[aux].render((SCREEN_WIDTH / BOARD_COLUMNS) * (x + j), (SCREEN_HEIGHT / BOARD_ROWS) * (y + i));
            }
        }
    }
}


bool checkCollision(int *x, int *y, int *shape, int *rotation, Timer *timer, int *seconds, const int acceleration) {
    // If half a second has passed
    if ((*timer).getTicks() - *seconds >= HALF_SECOND - acceleration) {
        if (!tentativePosition(*x, *y + 1, *shape, *rotation)) {
            updateBoard(*x, *y, *shape, *rotation);
            *shape = rand() % TOTAL_PIECES;
            *rotation = rand() % ROTATIONS;
            *x = rand() % (BOARD_COLUMNS - calculatePieceWidth(*shape, *rotation));
            *y = 0;
            return true;
        } else {
            // Reset second counter and increment y for the next iteration
            *seconds = (*timer).getTicks();
            ++(*y);
        }
    }
    
    return false;
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
    
    // Runs the whole board
    for (int y = 0; y < BOARD_ROWS; ++y) {
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


// Tentative position
bool tentativePosition(const int x, const int y, const int shape, const int rotation) {
    for (int i = 0; i < PIECE_SIDE; ++i) {
        int yAux = y + i;
        for (int j = 0; j < PIECE_SIDE; ++j) {
            int xAux = x + j;
            // If the piece is gonna collide with another,
            // the piece is out of y bounds or the piece
            // is out of x bounds, is not a valid position
            if ((pieces[shape][i][j][rotation] != -1 && board[yAux][xAux] != -1) ||
                (pieces[shape][i][j][rotation] != -1 && yAux > BOARD_ROWS - 1) ||
                (x < 0 || x >= BOARD_COLUMNS)) {
                return false;
            }
        }
    }
    return true;
}


// Calculates the piece width
int calculatePieceWidth(const int shape, const int rotation) {
    int width = 0;
    int widthAux = 0;
    for (int i = 0; i < PIECE_SIDE; ++i) {
        for (int j = 0; j < PIECE_SIDE; ++j) {
            if (pieces[shape][i][j][rotation] != -1) {
                widthAux = j;
            }
        }
        if (widthAux > width) {
            width = widthAux;
        }
    }
    return width;
}


bool gameOver() {
    for (int x = 0; x < BOARD_COLUMNS; ++x) {
        if (board[0][x] != -1) {
            return true;
        }
    }
    return false;
}
