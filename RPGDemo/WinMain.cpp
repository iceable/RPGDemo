#include "globaldef.h"
#include "hge\include\hge.h"
#include "control\GameControler.h"

#pragma comment(lib, "hge/lib/hge.lib")
#pragma comment(lib, "hge/lib/hgehelp.lib")

HGE* hge = NULL;
GameControler* game;

SceneEngine* SceneEngine_ = NULL;

bool Update()
{
    game->Update();
    return false;
}

bool Render()
{
    game->Render();
    return false;
}


int WINAPI WinMain(          HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpCmdLine,
    int nCmdShow
)
{
    hge = hgeCreate(HGE_VERSION);
    
    hge->System_SetState(HGE_FRAMEFUNC, Update);
    hge->System_SetState(HGE_RENDERFUNC, Render);
    hge->System_SetState(HGE_FPS, 60);
    hge->System_SetState(HGE_TITLE, "RPG Demo");
    hge->System_SetState(HGE_SHOWSPLASH, false); //����ʾHGE��LOGO
    hge->System_SetState(HGE_WINDOWED, true); 

    SceneEngine_ = SceneEngine::Instance();
    SceneEngine_->Initialize();

    if (hge->System_Initiate())
    {
        game = GameControler::Instance();
        game->Start();
        hge->System_Start();
        //hge->System_Shutdown();
    }
    else
    {
        MessageBox(NULL, "��������ʧ��", NULL, MB_OK);
    }

    return 0;
}