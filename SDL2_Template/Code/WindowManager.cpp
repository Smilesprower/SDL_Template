//
// Created by Jay on 04/03/2018.
//

#include "WindowManager.h"

WindowManager::WindowManager(const char* name, int width, int height, uint32_t windowFlags, uint32_t rendererFlags)
    : m_isOpen{ true }
    , m_window{ SDL_CreateWindow(name, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, windowFlags) }
    , m_renderer{ SDL_CreateRenderer(m_window.get(), -1, rendererFlags) } {

        if(m_window == nullptr || m_renderer == nullptr) {
            m_isOpen = false;
        }
}

void WindowManager::update() {
    SDL_Event event;
    while(SDL_PollEvent(&event) != 0) {
        if(event.type == SDL_QUIT) {
            m_isOpen = false;
        } else {
            m_eventManager.updateEvent(event);
        }
    }
    m_eventManager.updateKeyBoardEvents();
    m_eventManager.updateGameControllerEvents();
}

void WindowManager::beginDraw() const {
    SDL_SetRenderDrawColor(m_renderer.get(), 100, 149, 237, 255);
    SDL_RenderClear(m_renderer.get());
}

void WindowManager::endDraw() const {
    SDL_RenderPresent(m_renderer.get());
}

bool WindowManager::isOpen() const {
    return m_isOpen;
}

void WindowManager::close() {
    m_isOpen = false;
}

SDL_Renderer* WindowManager::getRenderer() {
    return m_renderer.get();
}

EventManager* WindowManager::getEventManager() {
    return &m_eventManager;
}
