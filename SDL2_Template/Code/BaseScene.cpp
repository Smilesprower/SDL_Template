//
// Created by Jay on 04/03/2018.
//

#include "BaseScene.h"
#include "SceneManager.h"

SharedContext* BaseScene::getSharedContext() const {
    return m_sceneManager->getSharedContext();
}

void BaseScene::requestSceneChange(SceneID sceneID) {
    m_sceneManager->changeScene(sceneID);
}

void BaseScene::requestRemoveCurrentScene() {
    m_sceneManager->removeCurrentScene();
}

void BaseScene::requestRemoveAllScenes() {
    m_sceneManager->removeAllScenes();
}
