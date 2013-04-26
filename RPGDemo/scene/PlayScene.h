#ifndef PLAY_SCENE
#define PLAY_SCENE

#include "..\hge\include\hgesprite.h"
#include "../control/controlobject/Texture.h"
#include "../gameobject/people/playerrole.h"
#include "Scene.h"
#include "../gameobject/map/gamemap.h"
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
    GameMap* m_Map;
    PlayerRole* m_PlayerRole;
};

#endif