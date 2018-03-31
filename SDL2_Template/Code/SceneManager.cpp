//
// Created by Jay on 04/03/2018.
//

#include "SceneManager.h"

SceneManager::SceneManager(SharedContext& sharedContext)
    : m_sharedContext{ &sharedContext } {
}

void SceneManager::update() {
    if (!m_sceneStack.empty()) {
        m_sceneStack.back().second->update();
    }
}

void SceneManager::render() {
    //TODO : Add Transparency to allow multi scene draw ?
    if (!m_sceneStack.empty()) {
        m_sceneStack.back().second->render();
    }
}

bool SceneManager::sceneStackIsEmpty() {
    return m_sceneStack.empty();
}

void SceneManager::changeScene(SceneID sceneID) {
    if(!stackContainsScene(sceneID)) {
        m_sceneRequests.emplace_back(Request{ Request::Action::kAddScene, sceneID });
    } else {
        printf("Scene exists already\n");
    }
}

void SceneManager::removeCurrentScene() {
    m_sceneRequests.emplace_back(Request{ Request::Action::kRemoveCurrentScene });
}

void SceneManager::removeAllScenes() {
    m_sceneRequests.emplace_back(Request{ Request::Action::kRemoveAllScenes });
}

void SceneManager::processRequests() {
    for (const auto& requestItr : m_sceneRequests) {
        switch (requestItr.m_action) {
            case Request::Action::kAddScene: {
                addScene(requestItr.m_sceneID);
                break;
            }
            case Request::Action::kRemoveCurrentScene: {
                m_sceneStack.back().second->onExit();
                m_sceneStack.pop_back();
                m_sharedContext->eventManager->updateCurrentScene(m_sceneStack.back().first);
                break;
            }
            case Request::Action::kRemoveAllScenes: {
                while (!m_sceneStack.empty()) {
                    m_sceneStack.back().second->onExit();
                    m_sceneStack.pop_back();
                }
                break;
            }
        }
    }
    m_sceneRequests.clear();
}

void SceneManager::addScene(const SceneID sceneID) {
    auto sceneItr = m_sceneFactory.find(sceneID);
    if (sceneItr != m_sceneFactory.end()) {
        m_sharedContext->eventManager->updateCurrentScene(sceneID);
        m_sceneStack.emplace_back(std::make_pair(sceneID, std::move(sceneItr->second())));
        m_sceneStack.back().second->onEnter();
    }
    else {
        // TODO : END PROGRAM MAYBE ?
        printf("Scene is not registered\n");
    }
}

bool SceneManager::stackContainsScene(SceneID sceneID) {
    for (const auto& sceneItr : m_sceneStack) {
        if (sceneItr.first == sceneID) {
            return true;
        }
    }
    return false;
}

SharedContext* SceneManager::getSharedContext() const {
    return m_sharedContext;
}

SceneManager::Request::Request(SceneManager::Request::Action action, SceneID sceneID)
    : m_action{ action }, m_sceneID{ sceneID } {
}
