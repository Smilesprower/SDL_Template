//
// Created by Jay on 04/03/2018.
//

#include "App.h"
#include "TitleScene.h"
#include "GameScene.h"

App::App(const char *name, int32_t width, int32_t height, uint32_t windowFlags, uint32_t rendererFlags)
    : m_windowManager{ name, width, height, windowFlags, rendererFlags } {
        setUpClasses();
        setUpScenes();
}

void App::gameLoop() {

    while (m_windowManager.isOpen()) {

        // WINDOW EVENT UPDATES
        m_windowManager.update();

        // SCENE UPDATES
        m_sceneManager->update();

        // SCENE RENDERING
        m_windowManager.beginDraw();
        m_sceneManager->render();
        m_windowManager.endDraw();

        // LATE UPDATE
        m_sceneManager->processRequests();

        if (m_sceneManager->sceneStackIsEmpty()) {
            m_windowManager.close();
        }
    }
}

void App::setUpClasses() {
    m_sharedContext.renderer = m_windowManager.getRenderer();
    m_sharedContext.eventManager = m_windowManager.getEventManager();
    m_sceneManager = std::make_unique<SceneManager>(m_sharedContext);
}

void App::setUpScenes() {
    m_sceneManager->registerScene<TitleScene>(SceneID::kTitle);
    m_sceneManager->registerScene<GameScene>(SceneID::kGame);
    m_sceneManager->changeScene(SceneID::kTitle);
}