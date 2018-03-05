//
// Created by Jay on 04/03/2018.
//

#ifndef SDL2_TEMPLATE_BASESCENE_H
#define SDL2_TEMPLATE_BASESCENE_H

#include "SharedContext.h"
#include "Identifiers.h"

class SceneManager;
class BaseScene {
public:
    BaseScene(SceneManager& sceneManager)
        : m_sceneManager{ &sceneManager } {
    }
    //virtual ~BaseScene() = 0;

    virtual void update() = 0;
    virtual void render() = 0;

    virtual void onEnter() = 0;
    virtual void onExit() = 0;

protected:
    SharedContext* getSharedContext() const;
    void requestSceneChange(SceneID sceneID);
    void requestRemoveCurrentScene();
    void requestRemoveAllScenes();

private:
    SceneManager* m_sceneManager;
};

#endif //SDL2_TEMPLATE_BASESCENE_H
