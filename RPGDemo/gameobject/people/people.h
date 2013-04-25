#ifndef PEOPLE_
#define PEOPLE_

#include "../Sprite.h"
#include "../../control/controlobject/Texture.h"
#include <string>

class People : public SpriteBase
{
public:
    People(const std::string& strPath);
    virtual ~People();

    virtual bool IsVaild();

protected:
    int m_HP;
    int m_HPMax;
    int m_MP;
    int m_MPMax;
    Texture m_Direction[Direction_Tail];
};

#endif