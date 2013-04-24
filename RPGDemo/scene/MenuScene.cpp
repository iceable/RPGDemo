#include "../globaldef.h"
#include "MenuScene.h"

MenuScene::MenuScene()
{
    m_bgImgTex = hge->Texture_Load("res\\img\\menubg.png");
    m_bgImg = new hgeSprite(m_bgImgTex, 0, 0, 800, 600);
}

MenuScene::~MenuScene()
{
}

void MenuScene::Reset()
{
}

bool MenuScene::Output()
{
    hge->Gfx_BeginScene();
    m_bgImg->Render(10,10);
    hge->Gfx_EndScene();
    return true;
}

bool MenuScene::Update()
{
    return true;
}