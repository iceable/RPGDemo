#ifndef INPUTENGINE_
#define INPUTENGINE_

#include "../unit/Singleton.h"
#include "../gameobject/Sprite.h"
#include <vector>

class InputEngine : public Singleton<InputEngine>
{
    friend class Singleton<Singleton>;
public:
    InputEngine();
    virtual ~InputEngine();

    virtual bool Initialize();

    PeopleDirection Get() const;

    void Update(int nKey);

private:
     PeopleDirection m_Key;
};

#endif