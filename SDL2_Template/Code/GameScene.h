//
// Created by Jay on 04/03/2018.
//

#ifndef SDL2_TEMPLATE_GAMESCENE_H
#define SDL2_TEMPLATE_GAMESCENE_H

#include "BaseScene.h"

class GameScene : public BaseScene{
public:
    GameScene(SceneManager& sceneManager);

    void update() override;
    void render() override;
    void onEnter() override;
    void onExit() override;

private:
};



#endif //SDL2_TEMPLATE_GAMESCENE_H
