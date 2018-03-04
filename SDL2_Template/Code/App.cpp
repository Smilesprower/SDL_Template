//
// Created by Jay on 04/03/2018.
//

#include "App.h"
#include "TitleScene.h"
#include "GameScene.h"

App::App()
    : m_quit(false) {
}


bool App::init() {

    if(m_window.init("", 800, 600, SDL_WINDOW_INPUT_FOCUS, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC)) {
        setUpClasses();
        return true;
    }
    return false;
}

void App::loop() {
    while (!m_quit) {
        SDL_Event event;
        // Keyboard Update
        while(SDL_PollEvent(&event) != 0) {
            switch(event.type) {
                case SDL_QUIT: {
                    m_quit = true;
                }
            }
        }

        // HANDLE TIME
        // HANDLE INPUT

        m_sceneManager->update();

        SDL_RenderClear(m_window.getRenderer());
        m_sceneManager->render();
        SDL_RenderPresent(m_window.getRenderer());

        m_sceneManager->processRequests();

        if (m_sceneManager->sceneStackIsEmpty()) {
            m_quit = true;
        }
    }
}

void App::cleanUp() {
}

void App::setUpClasses() {


    m_sceneManager = std::make_unique<SceneManager>(m_sharedContext);

    m_sceneManager->registerScene<TitleScene>(SceneID::kTitle);
    m_sceneManager->registerScene<GameScene>(SceneID::kGame);
    m_sceneManager->changeScene(SceneID::kTitle);
}

void App::loadContent() {
}