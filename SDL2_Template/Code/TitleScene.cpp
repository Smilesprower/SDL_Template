//
// Created by Jay on 04/03/2018.
//

#include "TitleScene.h"

TitleScene::TitleScene(SceneManager& sceneManager)
    : BaseScene{ sceneManager }
    , m_bounds { 50,50,200,200 }
    , m_velocity { 0, 0 } {
}

void TitleScene::update() {
    m_bounds.x += m_velocity.x;
    m_bounds.y += m_velocity.y;

    m_velocity.x = 0;
    m_velocity.y = 0;
}

void TitleScene::render() {
    SDL_Renderer* renderer = getSharedContext()->renderer;
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &m_bounds);
}

void TitleScene::onEnter() {
    // Update SharedContext managers
    EventManager* eventManager = getSharedContext()->eventManager;
    eventManager->addCallback(EventID::kUp,    &TitleScene::moveUp,    this);
    eventManager->addCallback(EventID::kDown,  &TitleScene::moveDown,  this);
    eventManager->addCallback(EventID::kLeft,  &TitleScene::moveLeft,  this);
    eventManager->addCallback(EventID::kRight, &TitleScene::moveRight, this);
}

void TitleScene::onExit() {
    // Clear SharedContext managers
}

void TitleScene::moveUp(EventInfo *info) {
    m_velocity.y-=1;
}

void TitleScene::moveDown(EventInfo *info) {
    m_velocity.y+=1;
}

void TitleScene::moveLeft(EventInfo *info) {
    m_velocity.x-=1;
}

void TitleScene::moveRight(EventInfo *info) {
    m_velocity.x+=1;
}
