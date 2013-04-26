#include "../globaldef.h"
#include "PlayScene.h"

PlayScene::PlayScene()
{
    m_Map = new GameMap;
    m_Map->Load("res\\img\\map.png", "res\\img\\mapcollision.png");

    m_PlayerRole = new PlayerRole(400, 300);
}

PlayScene::~PlayScene()
{
    delete m_Map;
    delete m_PlayerRole;
}

void PlayScene::Reset()
{
    hge->Gfx_Clear(ARGB(1,0,0,0));
}

void PlayScene::Output()
{
    m_Map->Render();
    m_PlayerRole->Render();
}

void PlayScene::Update()
{
    roleVector nextPos = m_PlayerRole->GetNextPos();
    if (!m_Map->isCollision(nextPos, ARGB(255,255,255,255))) ///����ײ��ɫ ���ƶ�
    {
        m_PlayerRole->MoveTo(nextPos);
    }
}