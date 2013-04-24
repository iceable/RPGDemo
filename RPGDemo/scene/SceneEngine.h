#ifndef SCENE_ENGINE
#define SCENE_ENGINE
#include "../stdafx.h"
#include "../control/GameControler.h"
#include "Scene.h"


class SceneEngine
    :public Singleton<SceneEngine>
{
    friend class Singleton<SceneEngine>;
public:
    virtual ~SceneEngine();

    virtual bool Initialize();

    void Push(Scene* pScene);
    void Pop();
    void PopAll();

    bool Update();
    void Output();

private:
    SceneEngine();

    std::vector<Scene*>     m_GameStack;
    std::vector<Scene*>     m_PushStack;
    bool                        m_bStatusChange;
    int                         m_nPopCount;

};

#endif