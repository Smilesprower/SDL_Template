//
// Created by Jay on 04/03/2018.
//

#include "GameScene.h"
GameScene::GameScene(SceneManager& sceneManager)
        : BaseScene{ sceneManager } {
}

void GameScene::update() {
}

void GameScene::render() {
}

void GameScene::onEnter() {
    // Update SharedContext managers
    requestRemoveAllScenes();
}

void GameScene::onExit() {
    // Clean SharedContext managers
}