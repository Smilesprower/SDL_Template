//
// Created by Jay on 31/03/2018.
//

#ifndef SDL2_TEMPLATE_SDL2UNIQUEPTR_H
#define SDL2_TEMPLATE_SDL2UNIQUEPTR_H

#include <memory>
struct SDL2UniquePtr {
    void operator()(SDL_Window* window) {
        if (window) {
            SDL_DestroyWindow(window);
        }
    }
    void operator()(SDL_Renderer* renderer) {
        if (renderer) {
            SDL_DestroyRenderer(renderer);
        }
    }
    void operator()(SDL_Surface* surface) {
        if (surface) {
            SDL_FreeSurface(surface);
        }
    }
    void operator()(SDL_Texture* texture) {
        if (texture) {
            SDL_DestroyTexture(texture);
        }
    }
    void operator()(SDL_GameController* gameController) {
        if (gameController) {
            SDL_GameControllerClose(gameController);
        }
    }
};

// <-- Unique Pointers -->
using SDL2uWindow            = std::unique_ptr<SDL_Window, SDL2UniquePtr>;
using SDL2uRenderer          = std::unique_ptr<SDL_Renderer, SDL2UniquePtr>;
using SDL2uSurface           = std::unique_ptr<SDL_Surface, SDL2UniquePtr>;
using SDL2uTexture           = std::unique_ptr<SDL_Texture, SDL2UniquePtr>;
using SDL2uGameController    = std::unique_ptr<SDL_GameController, SDL2UniquePtr>;

#endif //SDL2_TEMPLATE_SDL2UNIQUEPTR_H
