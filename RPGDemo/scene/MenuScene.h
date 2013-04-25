#ifndef MENU_SCENE
#define MENU_SCENE

#include "..\hge\include\hgesprite.h"
#include "../control/controlobject/Texture.h"
#include "Scene.h"

class MenuScene
    :public Scene
{
public:
    MenuScene();
    ~MenuScene();
    void Update();
    void Output();
    void Reset();
private:
    Texture m_bgTexture;
    HEFFECT m_bgMusic;
};

#endif