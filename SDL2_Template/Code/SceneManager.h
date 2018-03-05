//
// Created by Jay on 04/03/2018.
//

#ifndef SDL2_TEMPLATE_SCENEMANAGER_H
#define SDL2_TEMPLATE_SCENEMANAGER_H

#include <map>
#include <vector>
#include <memory>
#include <functional>
#include "BaseScene.h"
#include "SharedContext.h"
#include "Identifiers.h"

class SceneManager {
public:
    enum class Action {
        kAddScene, kRemoveCurrentScene, kRemoveAllScenes
    };

    explicit SceneManager(SharedContext& sharedContext);

    void update();
    void render();

    bool sceneStackIsEmpty();

    template <typename T>
    void registerScene(SceneID sceneID);

    void changeScene(const SceneID sceneID);
    void removeCurrentScene();
    void removeAllScenes();
    void processRequests();

    SharedContext* getSharedContext() const;

private:
    struct Request {
        Request(Action action, SceneID sceneID = SceneID::kNone);
        Action m_action;
        SceneID m_sceneID;
    };

    using SceneRequests = std::vector<Request>;
    using SceneStack = std::vector<std::pair<SceneID, std::unique_ptr<BaseScene>>>;
    using SceneFactory = std::map<SceneID, std::function<std::unique_ptr<BaseScene>()>>;

    void addScene(SceneID sceneID);
    bool stackContainsScene(SceneID sceneID);


    SharedContext* m_sharedContext;
    SceneRequests m_sceneRequests;
    SceneStack m_sceneStack;
    SceneFactory m_sceneFactory;
};

template <typename T>
void SceneManager::registerScene(SceneID sceneID) {
    m_sceneFactory[sceneID] = [this]() {
        return std::make_unique<T>(*this);
    };
}

#endif //SDL2_TEMPLATE_SCENEMANAGER_H
