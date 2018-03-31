//
// Created by Jay on 05/03/2018.
//

#ifndef SDL2_TEMPLATE_KEYBOARD_H
#define SDL2_TEMPLATE_KEYBOARD_H

#include <algorithm>
#include "EventInfo.h"
struct Keyboard {
    Keyboard()
        : m_currentState(SDL_GetKeyboardState(nullptr)) {
    }

    void updatePreviousState() {
        std::copy(m_currentState, (m_currentState + SDL_SCANCODE_NONUSBACKSLASH), m_previousState);
    }

    InputState getState(const SDL_Scancode kCode) {
        if (!m_previousState[kCode]) {
            if (!m_currentState[kCode]) {
                return InputState::kNone;
            }
            return InputState::kKeyPress;
        } else if (!m_currentState[kCode]) {
            return InputState::kKeyUp;
        } else {
            return InputState::kKeyDown;
        }
    }

private:
    const Uint8* m_currentState;
    Uint8 m_previousState[SDL_SCANCODE_NONUSBACKSLASH];
};

#endif //SDL2_TEMPLATE_KEYBOARD_H
