//
// Created by Jay on 04/03/2018.
//

#ifndef SDL2_TEMPLATE_WINDOW_H
#define SDL2_TEMPLATE_WINDOW_H

#include <SDL2/SDL.h>
#include "EventManager.h"
#include "Keyboard.h"
#include "SDL2UniquePtr.h"

class WindowManager {
public:
    WindowManager(const char* name, int32_t width, int32_t height, uint32_t windowFlags, uint32_t rendererFlags);

    void update();
    void beginDraw() const;
    void endDraw() const;

    bool isOpen() const;
    void close();

    SDL_Renderer* getRenderer();
    EventManager* getEventManager();

private:
    bool m_isOpen;
    EventManager m_eventManager;
    SDL2uWindow m_window;
    SDL2uRenderer m_renderer;
};


#endif //SDL2_TEMPLATE_WINDOW_H
