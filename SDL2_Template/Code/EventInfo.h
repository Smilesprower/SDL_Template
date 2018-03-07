//
// Created by Jay on 07/03/2018.
//

#ifndef SDL2_TEMPLATE_EVENTINFO_H
#define SDL2_TEMPLATE_EVENTINFO_H

enum class CommandID {
    kUp, kDown, kLeft, kRight
};

enum class EventID {
    kKeyDown, kKeyUp, kKeyPress
};

struct EventInfo {
    EventID eventId;
    SDL_Scancode keyCode;
};

#endif //SDL2_TEMPLATE_EVENTINFO_H
