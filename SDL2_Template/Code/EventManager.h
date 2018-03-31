//
// Created by Jay on 05/03/2018.
//

#ifndef SDL2_TEMPLATE_EVENTMANAGER_H
#define SDL2_TEMPLATE_EVENTMANAGER_H

#include <SDL2/SDL.h>
#include <unordered_map>
#include <functional>
#include <vector>
#include "Identifiers.h"
#include "Keyboard.h"
#include "../WIP/GameController.h"
#include "EventInfo.h"
#include <iostream>

class EventManager {
public:
    EventManager();

    void setUp();

    void updateEvent(SDL_Event& event);
    void updateKeyBoardEvents();
    void updateGameControllerEvents();
    void updateCurrentScene(SceneID sceneID);

    template<class T>
    void addCallback(EventID eventID, void(T::*func)(EventInfo*), T* instance);

private:
    using Callback = std::unordered_map<EventID, std::function<void(EventInfo*)>>;
    using Bindings = std::unordered_map<EventID, EventInfo>;

    void callback(EventID eventID, EventInfo* eventInfo);

    SceneID m_currentScene;
    Keyboard m_keyboard;
    //GameController m_gameController;
    Callback m_callbacks;

    // TODO : Load from file ?
    Bindings m_bindings{
            { EventID::kUp,		EventInfo{ InputState::kKeyDown,   SDL_SCANCODE_UP,     }},
            { EventID::kDown,	EventInfo{ InputState::kKeyDown,   SDL_SCANCODE_DOWN,   }},
            { EventID::kLeft,	EventInfo{ InputState::kKeyDown,   SDL_SCANCODE_LEFT,   }},
            { EventID::kRight,	EventInfo{ InputState::kKeyDown,   SDL_SCANCODE_RIGHT,  }},
    };
};

template<class T>
void EventManager::addCallback(EventID cmdId, void(T::*func)(EventInfo*), T* instance) {
    m_callbacks.emplace(cmdId, [instance, func] (EventInfo* info) {
        (instance->*func)(info);
    });
}

#endif //SDL2_TEMPLATE_EVENTMANAGER_H
