//
// Created by Jay on 05/03/2018.
//

#ifndef SDL2_TEMPLATE_EVENTMANAGER_H
#define SDL2_TEMPLATE_EVENTMANAGER_H

#include <SDL2/SDL.h>
#include "Keyboard.h"

class EventManager {
public:
    void updateEvent(SDL_Event& event);
    void updateRealTimeEvent();

private:
    Keyboard m_keyboard;
};


#endif //SDL2_TEMPLATE_EVENTMANAGER_H
