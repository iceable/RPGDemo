#ifndef PLAY_SCENE
#define PLAY_SCENE

#include "..\hge\include\hgesprite.h"
#include "../control/controlobject/Texture.h"
#include "../gameobject/people/selfpeople.h"
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
    Texture m_MapTexture;
    SelfPeople* m_SelfPeople;
};

#endif