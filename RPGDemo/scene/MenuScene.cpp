#include "../globaldef.h"
#include "MenuScene.h"

MenuScene::MenuScene()
{
    m_bgImgTex = hge->Texture_Load("res\\img\\menubg.png");
    m_bgImg = new hgeSprite(m_bgImgTex, 0, 0, 800, 600);
    m_bgMusic = hge->Effect_Load("res\\music\\bg.mp3");
    hge->Effect_PlayEx(m_bgMusic, 100, 0, 1.0, true);
}

MenuScene::~MenuScene()
{
    hge->Channel_Stop(m_bgMusic);
    hge->Effect_Free(m_bgMusic);
    hge->Texture_Free(m_bgImgTex);
    delete m_bgImg;
}

void MenuScene::Reset()
{
}

void MenuScene::Output()
{
    m_bgImg->Render(0,0);
}

void MenuScene::Update()
{
    if (hge->Input_GetKeyState(HGEK_ESCAPE))
    {
        SceneEngine_->Pop();
    }
    if (hge->Input_GetKeyState(HGEK_ENTER))
    {

    }
}