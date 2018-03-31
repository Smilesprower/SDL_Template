//
// Created by Jay on 07/03/2018.
//

#ifndef SDL2_TEMPLATE_JOYSTICK_H
#define SDL2_TEMPLATE_JOYSTICK_H

#include <array>
#include <algorithm>
#include <SDL2/SDL.h>
#include "../Code/SDL2UniquePtr.h"

struct ControllerData {
    std::array<Uint8, SDL_CONTROLLER_BUTTON_MAX> previousButtonState{ 0 };
    std::array<Uint8, SDL_CONTROLLER_BUTTON_MAX> currentButtonState{ 0 };
    //std::array<int16_t, SDL_CONTROLLER_AXIS_MAX> axisState{ 0 };
};


struct GameController {
    void updateCurrentState() {
        for(int i = 0; i < SDL_CONTROLLER_BUTTON_MAX; i++) {
            m_controller.second.currentButtonState[i] =
                SDL_GameControllerGetButton(m_controller.first.get(), static_cast<SDL_GameControllerButton>(i));
        }
//        for(int i = 0; i < SDL_CONTROLLER_AXIS_MAX; i++) {
//            m_controller.second.axisState[i] =
//                    SDL_GameControllerGetAxis(m_controller.first.get(), static_cast<SDL_GameControllerAxis>(i));
//        }
    }

    void updatePreviousState() {
        m_controller.second.previousButtonState = m_controller.second.currentButtonState;
    }

    bool onKeyPress(const SDL_GameControllerButton kCode) const {
        return m_controller.second.currentButtonState[kCode] == 1
            && m_controller.second.previousButtonState[kCode] == 0;
    }

    bool onKeyDown(const SDL_GameControllerButton kCode) const {
        return m_controller.second.currentButtonState[kCode] == 1;
    }

    bool onKeyUp(const SDL_GameControllerButton kCode) const {
        return m_controller.second.currentButtonState[kCode] == 0
            && m_controller.second.previousButtonState[kCode] == 1;
    }

//    int16_t onAxis(const SDL_GameControllerAxis kCode) const {
//        if(m_controller.second.axisState[kCode] > kDeadZone ||
//            m_controller.second.axisState[kCode] < -kDeadZone) {
//            return m_controller.second.axisState[kCode];
//        }
//        return 0;
//    }

    void setGameController(SDL_GameController* controller) {
        m_controller.first.reset(controller);
    }

private:
    using Controller = std::pair<SDL2uGameController , ControllerData>;

    const static int16_t kDeadZone = 5000;
    Controller m_controller;
};

#endif //SDL2_TEMPLATE_JOYSTICK_H
