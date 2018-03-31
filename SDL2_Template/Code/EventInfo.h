//
// Created by Jay on 07/03/2018.
//

#ifndef SDL2_TEMPLATE_EVENTINFO_H
#define SDL2_TEMPLATE_EVENTINFO_H

enum class EventID {
    kUp, kDown, kLeft, kRight
};

enum class InputState {
    kNone, kKeyDown, kKeyUp, kKeyPress
};

struct EventInfo {
    InputState inputState;
    SDL_Scancode keyCode;
};

#endif //SDL2_TEMPLATE_EVENTINFO_H
