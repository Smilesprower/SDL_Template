//
// Created by Jay on 04/03/2018.
//

#include "SceneManager.h"

SceneManager::SceneManager(SharedContext& sharedContext)
        : m_sharedContext{ sharedContext } {
}

void SceneManager::update() {
    //TEMP
    if (!m_sceneStack.empty()) {
        m_sceneStack.back().second->update();
    }
}

void SceneManager::render() {
    //TEMP
    if (!m_sceneStack.empty()) {
        m_sceneStack.back().second->render();
    }
}

bool SceneManager::sceneStackIsEmpty() {
    return m_sceneStack.empty();
}

void SceneManager::changeScene(SceneID sceneID) {
    m_sceneRequests.emplace_back(Request{ Action::kAddScene, sceneID });
}

void SceneManager::removeCurrentScene() {
    m_sceneRequests.emplace_back(Request{ Action::kRemoveCurrentScene });
}

void SceneManager::removeAllScenes() {
    m_sceneRequests.emplace_back(Request{ Action::kRemoveAllScenes });
}

void SceneManager::processRequests() {
    // TODO CHANGE
    for (const auto& requestItr : m_sceneRequests) {
        switch (requestItr.m_action) {
            case Action::kAddScene: {
                addScene(requestItr.m_sceneID);
                break;
            }
            case Action::kRemoveCurrentScene: {
                m_sceneStack.back().second->onExit();
                m_sceneStack.pop_back();
                break;
            }
            case Action::kRemoveAllScenes: {
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
        m_sceneStack.emplace_back(std::make_pair(sceneID, std::move(sceneItr->second())));
        m_sceneStack.back().second->onEnter();
    }
    else {
        /// TODO END PROGRAM MAYBE ?
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

SharedContext& SceneManager::getSharedContext() const {
    return m_sharedContext;
}

SceneManager::Request::Request(SceneManager::Action action, SceneID sceneID)
        : m_action{ action }, m_sceneID{ sceneID } {
}
