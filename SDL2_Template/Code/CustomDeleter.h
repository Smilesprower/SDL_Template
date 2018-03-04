//
// Created by Jay on 04/03/2018.
//

#ifndef SDL2_TEMPLATE_CUSTOMDELETER_H
#define SDL2_TEMPLATE_CUSTOMDELETER_H

#include <memory>

namespace SDL2 {
    struct SDL_Deleter {
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
    };

    // <-- Unique Pointers -->
    using WindowUniqPtr = std::unique_ptr<SDL_Window, SDL_Deleter>;
    using RendererUniqPtr = std::unique_ptr<SDL_Renderer, SDL_Deleter>;
    using SurfaceUniqPtr = std::unique_ptr<SDL_Surface, SDL_Deleter>;
    using TextureUniqPtr = std::unique_ptr<SDL_Texture, SDL_Deleter>;

    // TODO: add shared_ptrs

} // namespace SDL2

#endif //SDL2_TEMPLATE_CUSTOMDELETER_H
