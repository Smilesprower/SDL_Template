//
// Created by Jay on 04/03/2018.
//

#ifndef SDL2_TEMPLATE_APP_H
#define SDL2_TEMPLATE_APP_H

#include "SceneManager.h"
#include "Window.h"

class App {
public:

    App();
    bool init();
    void loop();
    void cleanUp();

private:
    void setUpClasses();
    void loadContent();

    bool m_quit;
    SharedContext m_sharedContext;
    Window m_window;
    std::unique_ptr<SceneManager> m_sceneManager;
};

#endif //SDL2_TEMPLATE_APP_H
