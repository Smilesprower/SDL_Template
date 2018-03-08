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
#include "GameController.h"
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
    void addCallback(CommandID cmdID, void(T::*func)(EventInfo*), T* instance);

private:
    using Callback = std::unordered_map<CommandID, std::function<void(EventInfo*)>>;
    using Bindings = std::unordered_map<CommandID, EventInfo>;

    void callback(CommandID cmdId, EventInfo* eventInfo);

    SceneID m_currentScene;
    Keyboard m_keyboard;
    GameController m_gameController;
    Callback m_callbacks;

    // TODO : Load from file ?
    Bindings m_bindings{
            { CommandID::kUp,		EventInfo{ EventID::kKeyDown,   SDL_SCANCODE_UP,    SDL_CONTROLLER_BUTTON_DPAD_UP }},
            { CommandID::kDown,		EventInfo{ EventID::kKeyDown,   SDL_SCANCODE_DOWN,  SDL_CONTROLLER_BUTTON_DPAD_DOWN }},
            { CommandID::kLeft,		EventInfo{ EventID::kKeyDown,   SDL_SCANCODE_LEFT,  SDL_CONTROLLER_BUTTON_DPAD_LEFT }},
            { CommandID::kRight,	EventInfo{ EventID::kKeyDown,   SDL_SCANCODE_RIGHT, SDL_CONTROLLER_BUTTON_DPAD_RIGHT }},
    };
};

template<class T>
void EventManager::addCallback(CommandID cmdId, void(T::*func)(EventInfo*), T* instance) {
    m_callbacks.emplace(cmdId, [instance, func] (EventInfo* info) {
        (instance->*func)(info);
    });
}

#endif //SDL2_TEMPLATE_EVENTMANAGER_H
