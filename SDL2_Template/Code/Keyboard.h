//
// Created by Jay on 05/03/2018.
//

#ifndef SDL2_TEMPLATE_KEYBOARD_H
#define SDL2_TEMPLATE_KEYBOARD_H

#include <algorithm>

struct Keyboard {
    Keyboard()
        : m_currentState(SDL_GetKeyboardState(nullptr)) {
    }

    void updatePreviousState() {
        std::copy(m_currentState, (m_currentState + SDL_NUM_SCANCODES), m_previousState);
    }

    bool onKeyPress(const SDL_Scancode kCode) const {
        return m_currentState[kCode] == 1 && m_previousState[kCode] == 0;
    }

    bool onKeyDown(const SDL_Scancode kCode) const {
        return m_currentState[kCode] == 1;
    }

    bool onKeyUp(const SDL_Scancode kCode) const {
        return m_currentState[kCode] == 0 && m_previousState[kCode] == 1;
    }

private:
    const Uint8* m_currentState;
    Uint8 m_previousState[SDL_NUM_SCANCODES];
};

#endif //SDL2_TEMPLATE_KEYBOARD_H
