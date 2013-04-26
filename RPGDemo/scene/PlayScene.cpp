#include "../globaldef.h"
#include "PlayScene.h"

PlayScene::PlayScene()
{
    m_MapTexture.Load("res\\img\\map.png", 0, 0);
    m_SelfPeople = new SelfPeople(200, 200);
}

PlayScene::~PlayScene()
{
}

void PlayScene::Reset()
{
    hge->Gfx_Clear(ARGB(1,0,0,0));
}

void PlayScene::Output()
{
    m_MapTexture.Render(0, 0);
    m_SelfPeople->Render();
}

void PlayScene::Update()
{
    m_SelfPeople->Update();
}