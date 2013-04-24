#include "GameControler.h"
#include "../scene/MenuScene.h"

template<> GameControler* Singleton<GameControler>::m_pInst = 0;

GameControler::GameControler()
{
}

GameControler::~GameControler()
{
}

void GameControler::Start()
{
   SceneEngine_->Push(new MenuScene);
}

bool GameControler::Update()
{
    return SceneEngine_->Update();
}

bool GameControler::Render()
{
    return SceneEngine_->Output();
}

bool GameControler::Initialize()
{
    return false;
}