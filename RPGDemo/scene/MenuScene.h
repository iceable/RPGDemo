#ifndef MENU_SCENE
#define MENU_SCENE
#include "Scene.h"

class MenuScene
    :public Scene
{
public:
    MenuScene();
    ~MenuScene();
    bool Update();
    bool Output();
    void Reset();
private:
    hgeSprite* m_bgImg;
    HTEXTURE m_bgImgTex;
};

#endif