//
// Created by Jay on 04/03/2018.
//

#include "Window.h"

bool Window::init(const char* name, uint32_t screenWidth, uint32_t screenHeight,
    uint32_t windowFlags, uint32_t rendererFlags) {

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        m_window.reset(SDL_CreateWindow(name, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
            screenWidth, screenHeight, windowFlags));

        if (m_window != nullptr) {
            m_renderer.reset(SDL_CreateRenderer(m_window.get(), -1, rendererFlags));
            SDL_SetRenderDrawColor(m_renderer.get(), 100, 149, 237, 255);
            if (m_renderer != nullptr) {
                return true;
            } // Renderer Failed
        } // Window Failed
    } // SDL_Init Failed
    return false;
}

SDL_Renderer* Window::getRenderer() {
    return m_renderer.get();
}