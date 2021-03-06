#ifndef INPUTENGINE_
#define INPUTENGINE_

#include "../unit/Singleton.h"
#include "../hge/include/hge.h"
#include "../gameobject/Sprite.h"
#include <vector>

typedef enum _KeyState
{
    Key_Down,
    Key_Up,
    Key_Fail,
}KeyState;

class InputEngine : public Singleton<InputEngine>
{
    friend class Singleton<Singleton>;
public:
    InputEngine();
    virtual ~InputEngine();

    virtual bool Initialize() {return true;};

    virtual bool Initialize(HGE* pHGE);

    PeopleDirection Get() const;

    KeyState IsKey(int nKey);

    KeyState IsKey(int nFirstKey, int nSecondKey);

    void Update();

private:
     PeopleDirection m_Key;
     HGE* m_HGE;
};

#endif