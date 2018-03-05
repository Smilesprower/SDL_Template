#include <iostream>
#include "App.h"

int main(int argc, char **argv) {
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        App app{ "SDL2", 800, 600, SDL_WINDOW_INPUT_FOCUS, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC };
        app.gameLoop();
    }
    SDL_Quit();
    return 0;
}
