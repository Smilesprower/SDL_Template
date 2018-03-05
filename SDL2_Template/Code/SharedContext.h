//
// Created by Jay on 04/03/2018.
//

#ifndef SDL2_TEMPLATE_SHAREDCONTEXT_H
#define SDL2_TEMPLATE_SHAREDCONTEXT_H

#include <SDL2/SDL.h>

class WindowManager;
class EventManager;

struct SharedContext {
    SDL_Renderer* renderer = nullptr;
    EventManager* eventManager = nullptr;
};


#endif //SDL2_TEMPLATE_SHAREDCONTEXT_H
