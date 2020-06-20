//
//  main.cpp
//  Tetris
//
//  Created by Andrés Caballero Toledo on 17/06/2020.
//  Copyright © 2020 act. All rights reserved.
//

#include "Common.h"
#include "SDLConfig.h"
#include "Tile.h"
#include "Board.h"
#include "Timer.h"

#include "SDL2/SDL.h"

#include <cstdlib>
#include <string>
#include <sstream>

int main(int argc, const char *argv[]) {
    // Start SDL and initialize window
    if (!init()) {
        printf("Failed to initialize!\n");
    } else {
        // Load media
        if (!loadMedia()) {
            printf("Failed to load media!\n");
        } else {
            // Load textures
            if(!loadTextures()) {
                printf("Failed to load textures!\n");
            } else {
                // Game loop flag
                bool quit = false;
                
                // Event handler
                SDL_Event e;
                
                //Set text color as black
                SDL_Color textColor = {0, 0, 0, 255};
                
                // Application timer
                Timer gameTimer;
                
                // In memory text stream
                std::stringstream timeText;
                
                // Start counting FPS
                int countedFrames = 0;
                int seconds = 0;
                gameTimer.start();
                
                // Timer texture
                Tile FPSTexture;
                
                // Active piece status
                srand(time(NULL));
                int xActive = rand() % BOARD_COLUMNS;
                int yActive = 0;
                int type = rand() % TOTAL_TILES;
                
                // Initialize the board
                initializeBoard();
                
                // Game loop
                while (!quit) {
                    // Handle events on queue
                    while (SDL_PollEvent(&e) != 0) {
                        if (e.type == SDL_QUIT) {
                            quit = true;
                        }
                    }
                    
                    // Calculate and correct FPS
                    float avgFPS = countedFrames / (gameTimer.getTicks() / 1000.f);
                    if (avgFPS > 2000000) {
                        avgFPS = 0;
                    }
                    if (countedFrames > 1000000) { // secure avoiding overflow
                        countedFrames = 0;
                    }
                    
                    // Set text to be rendered
                    timeText.str("");
                    timeText << "FPS: " << avgFPS;
                    
                    // Render Text
                    if (!FPSTexture.loadFromRenderedText(timeText.str().c_str(), textColor)) {
                        printf("Unable to render FPS texture!\n");
                    }
                    
                    // Clear screen
                    SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
                    SDL_RenderClear(gRenderer);
                    
                    // Draw board
                    drawBoard();
                    
                    // Draw current piece
                    drawTile(&xActive, &yActive, &type, &gameTimer, &seconds);
                    
                    // Check lines
                    if (checkLine()) {
                        updateColumns();
                    }
                    
                    // Render FPS counter
                    FPSTexture.render(0, 0);
                    
                    // Update screen
                    SDL_RenderPresent(gRenderer);
                    ++countedFrames;
                }
            }
        }
    }
    
    // Free resources and close SDL
    close();
    
    return EXIT_SUCCESS;
}
