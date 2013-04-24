#ifndef SCENE
#define SCENE
#include "../stdafx.h"


class Scene
{
public:
    Scene();
    ~Scene();

    virtual bool Update() = 0;
    virtual bool Output() = 0;
    virtual void Reset()  = 0;

private:

};

Scene::Scene()
{
}

Scene::~Scene()
{
}


#endif