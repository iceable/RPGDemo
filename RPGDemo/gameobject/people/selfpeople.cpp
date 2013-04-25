#include "../../globaldef.h"
#include "selfpeople.h"

SelfPeople::SelfPeople(int x, int y)
    : People(x, y)
    , m_Direction(Direction_Up)
{
    LoadPeopleImage("res\\img\\self.png", 8, 128, 128);
    m_nSpeed = 3;
    m_nPresentFrame = 0;
}

SelfPeople::~SelfPeople()
{
}

void SelfPeople::Render()
{
    if (m_nPresentFrame == m_nFrameCount)
    {
        m_nPresentFrame = 1;
    }
    m_DirectionTex[m_Direction].RenderFrame(
        m_nPresentFrame,(float)m_nPosX, (float)m_nPosY);
}

void SelfPeople::Update()
{
    float fDis = ElapsedTime * m_nSpeed;
    m_nPosX += int(cos(m_fAngle) * fDis);
    m_nPosY += int(sin(m_fAngle) * fDis);

    //根据运动决定下一个点位置
    if (hge->Input_GetKeyState(HGEK_UP) )
    {
        if (hge->Input_GetKeyState(HGEK_LEFT))
        {
            m_fAngle = 5.0f * M_PI / 4.0f;
            m_Direction = Direction_LeftUp;
            m_nPosX -= m_nSpeed;
            m_nPosY -= m_nSpeed;
        }
        else if (hge->Input_GetKeyState(HGEK_RIGHT))
        {
            m_fAngle = 2.0f * M_PI - M_PI / 4.0f;
            m_Direction = Direction_RightUp;
            m_nPosX += m_nSpeed;
            m_nPosY -= m_nSpeed;
        }
        else
        {
            m_fAngle = 3.0f * M_PI / 2.0f;
            m_Direction = Direction_Up;
            m_nPosY -= m_nSpeed;
        }
        m_nPresentFrame++;
    }
    else if (hge->Input_GetKeyState(HGEK_DOWN) )
    {
        if (hge->Input_GetKeyState(HGEK_LEFT))
        {
            m_fAngle = 3.0f * M_PI / 4.0f;
            m_Direction = Direction_LeftDown;
            m_nPosX -= m_nSpeed;
            m_nPosY += m_nSpeed;
        }
        else if (hge->Input_GetKeyState(HGEK_RIGHT))
        {
            m_fAngle = M_PI / 4.0f;
            m_Direction = Direction_RightDown;
            m_nPosX += m_nSpeed;
            m_nPosY += m_nSpeed;
        }
        else
        {
            m_fAngle = M_PI / 2.0f;
            m_Direction = Direction_Down;
            m_nPosY += m_nSpeed;
        }
        m_nPresentFrame++;
    }
    else if (hge->Input_GetKeyState(HGEK_LEFT) )
    {
        if (hge->Input_GetKeyState(HGEK_UP))
        {
            m_fAngle = 5.0f * M_PI / 4.0f;
            m_Direction = Direction_LeftUp;
            m_nPosX += m_nSpeed;
            m_nPosY -= m_nSpeed;
        }
        else if (hge->Input_GetKeyState(HGEK_DOWN))
        {
            m_fAngle = 3.0f * M_PI / 4.0f;
            m_Direction = Direction_LeftDown;
            m_nPosX -= m_nSpeed;
            m_nPosY += m_nSpeed;
        }
        else
        {
            m_fAngle = M_PI;
            m_Direction = Direction_Left;
            m_nPosX -= m_nSpeed;
        }
        m_nPresentFrame++;
    }
    else if (hge->Input_GetKeyState(HGEK_RIGHT) )
    {
        if (hge->Input_GetKeyState(HGEK_UP))
        {
            m_fAngle = 2.0f * M_PI - M_PI / 4.0f;
            m_Direction = Direction_RightUp;
            m_nPosX += m_nSpeed;
            m_nPosY -= m_nSpeed;
        }
        else if (hge->Input_GetKeyState(HGEK_DOWN))
        {
            m_fAngle = M_PI / 4.0f;
            m_Direction = Direction_RightDown;
            m_nPosX += m_nSpeed;
            m_nPosY -= m_nSpeed;
        }
        else
        {
            m_fAngle = 0.0f;
            m_Direction = Direction_Right;
            m_nPosX += m_nSpeed;
        }
        m_nPresentFrame++;
    }
}

bool SelfPeople::IsVaild()
{
    return true;
}