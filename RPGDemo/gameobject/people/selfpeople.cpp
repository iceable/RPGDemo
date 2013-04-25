#include "../../globaldef.h"
#include "selfpeople.h"

SelfPeople::SelfPeople(int x, int y)
    : People(x, y)
    , m_Direction(Direction_Up)
{
    LoadPeopleImage("res\\img\\self.png", 8, 130, 130);
    m_nSpeed = 3;
}

SelfPeople::~SelfPeople()
{
}

void SelfPeople::Render()
{
    m_DirectionTex[m_Direction].Render((float)m_nPosX, (float)m_nPosY);
}

void SelfPeople::Update()
{
    //根据运动决定下一个点位置
    if (hge->Input_GetKeyState(HGEK_UP) )
    {
        m_nPosY -= m_nSpeed;
        m_Direction = Direction_Up;
    }
    else if (hge->Input_GetKeyState(HGEK_DOWN) )
    {
        m_nPosY += m_nSpeed;
        m_Direction = Direction_Down;
    }
    else if (hge->Input_GetKeyState(HGEK_LEFT) )
    {
        m_nPosX -= m_nSpeed;
        m_Direction = Direction_Left;
    }
    else if (hge->Input_GetKeyState(HGEK_RIGHT) )
    {
        m_nPosX += m_nSpeed;
        m_Direction = Direction_Right;
    }
}

bool SelfPeople::IsVaild()
{
    return true;
}