#ifndef MENU_SCENE
#define MENU_SCENE

#include "..\hge\include\hgesprite.h"
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
    hgeSprite* m_bgImg;
    HTEXTURE m_bgImgTex;
    HEFFECT m_bgMusic;
};

#endif