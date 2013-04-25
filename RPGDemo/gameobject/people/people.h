#ifndef PEOPLE_
#define PEOPLE_

#include "../Sprite.h"
#include "../../control/controlobject/Texture.h"
#include <string>

class People : public SpriteBase
{
public:
    People(int x = 0, int y = 0);
    virtual ~People();

    virtual bool LoadPeopleImage(const std::string& strPath,
        int nFrame, int nWidth, int nHeight);

    virtual bool IsVaild() {return true;}

protected:
    int m_HP;
    int m_HPMax;
    int m_MP;
    int m_MPMax;
    Texture m_DirectionTex[Direction_Tail];
};

#endif