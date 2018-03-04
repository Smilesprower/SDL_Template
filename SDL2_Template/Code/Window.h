//
// Created by Jay on 04/03/2018.
//

#ifndef SDL2_TEMPLATE_WINDOW_H
#define SDL2_TEMPLATE_WINDOW_H

#include <SDL2/SDL.h>
#include "CustomDeleter.h"

class Window {
public:
    bool init(const char* name, uint32_t screenWidth, uint32_t screenHeight,
              uint32_t windowFlags, uint32_t rendererFlags);

    SDL_Renderer* getRenderer();

private:
    SDL2::WindowUniqPtr m_window;
    SDL2::RendererUniqPtr m_renderer;
};


#endif //SDL2_TEMPLATE_WINDOW_H
