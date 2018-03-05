//
// Created by Jay on 05/03/2018.
//

#include "EventManager.h"
void EventManager::updateEvent(SDL_Event &event) {
    // HANDLE EVENT STHUFF, MOUSE ETC
    //
}

void EventManager::updateRealTimeEvent() {
    // HANDLE KEYBOARD STHUFF IN REAL TIME

    // SET PREVIOUS STATE
    m_keyboard.updatePreviousState();
}
