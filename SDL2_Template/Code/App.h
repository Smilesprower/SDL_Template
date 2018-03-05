//
// Created by Jay on 04/03/2018.
//

#ifndef SDL2_TEMPLATE_APP_H
#define SDL2_TEMPLATE_APP_H

#include "SceneManager.h"
#include "WindowManager.h"

class App {
public:
    App(const char *name, int32_t width, int32_t height, uint32_t windowFlags, uint32_t rendererFlags);
    void gameLoop();

private:
    void setUpClasses();
    void setUpScenes();

    SharedContext m_sharedContext;
    WindowManager m_windowManager;
    std::unique_ptr<SceneManager> m_sceneManager;
};

#endif //SDL2_TEMPLATE_APP_H
