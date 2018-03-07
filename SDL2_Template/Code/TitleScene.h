//
// Created by Jay on 04/03/2018.
//

#ifndef SDL2_TEMPLATE_TITLESCENE_H
#define SDL2_TEMPLATE_TITLESCENE_H

#include "BaseScene.h"
#include "EventManager.h"
class TitleScene : public BaseScene {
public:
    TitleScene(SceneManager& sceneManager);

    void update() override;
    void render() override;
    void onEnter() override;
    void onExit() override;

private:
    void moveUp(EventInfo* info);
    void moveDown(EventInfo* info);
    void moveLeft(EventInfo* info);
    void moveRight(EventInfo* info);

    SDL_Point m_velocity;
    SDL_Rect m_bounds;
};


#endif //SDL2_TEMPLATE_TITLESCENE_H
