#ifndef GAME_CONTROLER
#define GAME_CONTROLER

#include "../unit/Singleton.h"
#include "../globaldef.h"


class GameControler
    :public Singleton<GameControler>
{
    friend class Singleton<GameControler>;
public:
    GameControler();
    ~GameControler();

    virtual bool Initialize();
    void Start();
    bool Update();
    bool Render();
    void Exit();

private:

};

#endif