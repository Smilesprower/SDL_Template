//
// Created by Jay on 05/03/2018.
//

#include "EventManager.h"

EventManager::EventManager()
    : m_currentScene{ SceneID::kNone } {
        setUp();
}

void EventManager::setUp() {
//    SDL_GameController* controller = SDL_GameControllerOpen(0);
//    if( controller == nullptr ) {
//        std::cout <<  "Unable to open game controller!" << std::endl;
//    } else {
//        std::cout << "Controller open" << std::endl;
//        m_gameController.setGameController(controller);
//    }
}

void EventManager::updateEvent(SDL_Event &event) {
    // HANDLE EVENT STHUFF, MOUSE ETC
}

void EventManager::updateKeyBoardEvents() {
    // HANDLE REAL TIME EVENTS
    for (auto& bindItr : m_bindings) {
        if(m_keyboard.getState(bindItr.second.keyCode) == bindItr.second.inputState) {
            callback(bindItr.first, &bindItr.second);
        }
    }
    // SET PREVIOUS STATE
    m_keyboard.updatePreviousState();
}

void EventManager::updateGameControllerEvents() {
//    m_gameController.updateCurrentState();
//
//    for (auto& bindItr : m_bindings) {
//        EventInfo* eventInfo = &bindItr.second;
//        switch(eventInfo->eventId) {
//            case EventID::kKeyDown : {
//                if (m_gameController.onKeyDown(eventInfo->buttonCode)) {
//                    callback(bindItr.first, eventInfo);
//                }   break;
//            }
//            case EventID::kKeyUp : {
//                if (m_gameController.onKeyUp(eventInfo->buttonCode)) {
//                    callback(bindItr.first, eventInfo);
//                }   break;
//            }
//            case EventID::kKeyPress : {
//                if (m_gameController.onKeyPress(eventInfo->buttonCode)) {
//                    callback(bindItr.first, eventInfo);
//                }   break;
//            }
//        }
//    }
//    m_gameController.updatePreviousState();
}

void EventManager::updateCurrentScene(SceneID sceneID) {
    m_currentScene = sceneID;
}

void EventManager::callback(EventID eventID, EventInfo* eventInfo) {
    auto callback = m_callbacks.find(eventID);
    if (callback != m_callbacks.end()) {
        callback->second(eventInfo);
    }
}



