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
#include "EventInfo.h"

class EventManager {
public:
    EventManager();

    void updateEvent(SDL_Event& event);
    void updateRealTimeEvent();
    void updateCurrentScene(SceneID sceneID);

    template<class T>
    void addCallback(CommandID cmdID, void(T::*func)(EventInfo*), T* instance);

private:
    using Callback = std::unordered_map<CommandID, std::function<void(EventInfo*)>>;
    using Bindings = std::unordered_map<CommandID, EventInfo>;

    void callback(CommandID cmdId, EventInfo* eventInfo);

    SceneID m_currentScene;
    Keyboard m_keyboard;
    Callback m_callbacks;

    // TODO : Load from file ?
    Bindings m_bindings{
            { CommandID::kUp,		EventInfo{ EventID::kKeyDown,  SDL_SCANCODE_UP }},
            { CommandID::kDown,		EventInfo{ EventID::kKeyDown,   SDL_SCANCODE_DOWN }},
            { CommandID::kLeft,		EventInfo{ EventID::kKeyDown,   SDL_SCANCODE_LEFT }},
            { CommandID::kRight,	EventInfo{ EventID::kKeyDown,   SDL_SCANCODE_RIGHT }},
    };
};

template<class T>
void EventManager::addCallback(CommandID cmdId, void(T::*func)(EventInfo*), T* instance) {
    m_callbacks.emplace(cmdId, [instance, func] (EventInfo* info) {
        (instance->*func)(info);
    });
}

#endif //SDL2_TEMPLATE_EVENTMANAGER_H
