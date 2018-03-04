//
// Created by Jay on 04/03/2018.
//

#ifndef SDL2_TEMPLATE_TITLESCENE_H
#define SDL2_TEMPLATE_TITLESCENE_H

#include "BaseScene.h"
class TitleScene : public BaseScene {
public:
    TitleScene(SceneManager& sceneManager);

    void update() override;
    void render() override;
    void onEnter() override;
    void onExit() override;

private:
};


#endif //SDL2_TEMPLATE_TITLESCENE_H
