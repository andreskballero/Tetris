//
//  Controls.cpp
//  Tetris
//
//  Created by Andrés Caballero Toledo on 21/06/2020.
//  Copyright © 2020 act. All rights reserved.
//

#include "Controls.h"

void movePiece(SDL_Event *e, bool *quit, int *x, int *y, int *rotation, int *acceleration, const int shape) {
    // Handle events on queue
    while (SDL_PollEvent(e) != 0) {
        if (e->type == SDL_QUIT) {
            *quit = true;
        } else if (e->type == SDL_KEYDOWN) {
            switch (e->key.keysym.sym) {
                case SDLK_RIGHT:
                    *x += 1;
                    for (int i = 0; i < PIECE_SIDE; ++i) {
                        for (int j = 0; j < PIECE_SIDE; ++j) {
                            if (pieces[shape][i][j][*rotation] != -1) {
                                if (*x + j > BOARD_COLUMNS - 1) {
                                    *x = BOARD_COLUMNS - j - 1;
                                } else if (board[*y + i][*x + j] != -1) {
                                    *x -= 1;
                                }
                            }
                        }
                    }
                    break;
                case SDLK_LEFT:
                    *x -= 1;
                    for (int i = 0; i < PIECE_SIDE; ++i) {
                        for (int j = 0; j < PIECE_SIDE; ++j) {
                            if (pieces[shape][i][j][*rotation] != -1) {
                                if (*x < 0) {
                                    *x = 0;
                                } else if (board[*y + i][*x + j] != -1) {
                                    *x += 1;
                                }
                            }
                        }
                    }
                    break;
                case SDLK_DOWN:
                    *acceleration = HALF_SECOND - 1;
                    break;
                case SDLK_SPACE:
                    *rotation += 1;
                    if (*rotation == ROTATIONS) {
                        *rotation = 0;
                    }
                    // Correct the position if the rotation brings the piece out
                    // of bounds
                    int width = calculatePieceWidth(shape, *rotation);
                    if (*x + width > BOARD_COLUMNS - 1) {
                        *x = BOARD_COLUMNS - 1 - width;
                    }
            }
        }
    }
}
