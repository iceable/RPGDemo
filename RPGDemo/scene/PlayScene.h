#ifndef PLAY_SCENE
#define PLAY_SCENE

#include "..\hge\include\hgesprite.h"
#include "Scene.h"

class PlayScene
    :public Scene
{
public:
    PlayScene();
    ~PlayScene();
    void Update();
    void Output();
    void Reset();
private:
};

#endif