#include "../../globaldef.h"
#include "selfpeople.h"

SelfPeople::SelfPeople(int x, int y)
    : People(x, y)
    , m_Direction(Direction_Up)
{
    LoadPeopleImage("res\\img\\self.png", 8, 128, 128);
    m_nSpeed = 3;
    m_nPresentFrame = 0;
    m_nTimeFrame = 0;
}

SelfPeople::~SelfPeople()
{
}

void SelfPeople::Render()
{
    if (m_nPresentFrame == m_nFrameCount)
    {
        m_nPresentFrame = 0;
    }
    if (m_nTimeFrame == MOVEFRAMEMAX)
    {
        m_nPresentFrame++;
        m_nTimeFrame = 0;
    }
    m_DirectionTex[m_Direction].RenderFrame(
        m_nPresentFrame,(float)m_nPosX, (float)m_nPosY);
}

void SelfPeople::ControlMove()
{
    if (InputEngine_->IsKey(HGEK_UP) == Key_Down)
    {
        if (InputEngine_->IsKey(HGEK_RIGHT) == Key_Down)
        {
            m_fAngle = 2.0f * M_PI - M_PI / 4.0f;
            m_Direction = Direction_RightUp;
            m_nPosX += m_nSpeed;
            m_nPosY -= m_nSpeed;
            m_nTimeFrame++;
        }
        else if (InputEngine_->IsKey(HGEK_LEFT) == Key_Down)
        {
            m_fAngle = 5.0f * M_PI / 4.0f;
            m_Direction = Direction_LeftUp;
            m_nPosX -= m_nSpeed;
            m_nPosY -= m_nSpeed;
            m_nTimeFrame++;
        }
        else
        {
            m_fAngle = 3.0f * M_PI / 2.0f;
            m_Direction = Direction_Up;
            m_nPosY -= m_nSpeed;
            m_nTimeFrame++;
        }
    }
    else if (InputEngine_->IsKey(HGEK_DOWN) == Key_Down)
    {
        if (InputEngine_->IsKey(HGEK_RIGHT) == Key_Down)
        {
            m_fAngle = M_PI / 4.0f;
            m_Direction = Direction_RightDown;
            m_nPosX += m_nSpeed;
            m_nPosY += m_nSpeed;
            m_nTimeFrame++;
        }
        else if (InputEngine_->IsKey(HGEK_LEFT) == Key_Down)
        {
            m_fAngle = 3.0f * M_PI / 4.0f;
            m_Direction = Direction_LeftDown;
            m_nPosX -= m_nSpeed;
            m_nPosY += m_nSpeed;
            m_nTimeFrame++;
        }
        else
        {
            m_fAngle = M_PI / 2.0f;
            m_Direction = Direction_Down;
            m_nPosY += m_nSpeed;
            m_nTimeFrame++;
        }
    }
    else if (InputEngine_->IsKey(HGEK_LEFT) == Key_Down)
    {
        if (InputEngine_->IsKey(HGEK_UP) == Key_Down)
        {
            m_fAngle = 5.0f * M_PI / 4.0f;
            m_Direction = Direction_LeftUp;
            m_nPosX -= m_nSpeed;
            m_nPosY -= m_nSpeed;
            m_nTimeFrame++;
        }
        else if (InputEngine_->IsKey(HGEK_DOWN) == Key_Down)
        {
            m_fAngle = 3.0f * M_PI / 4.0f;
            m_Direction = Direction_LeftDown;
            m_nPosX -= m_nSpeed;
            m_nPosY += m_nSpeed;
            m_nTimeFrame++;
        }
        else
        {
            m_fAngle = M_PI;
            m_Direction = Direction_Left;
            m_nPosX -= m_nSpeed;
            m_nTimeFrame++;
        }
    }
    else if (InputEngine_->IsKey(HGEK_RIGHT) == Key_Down)
    {
        if (InputEngine_->IsKey(HGEK_UP) == Key_Down)
        {
            m_fAngle = 2.0f * M_PI - M_PI / 4.0f;
            m_Direction = Direction_RightUp;
            m_nPosX += m_nSpeed;
            m_nPosY -= m_nSpeed;
            m_nTimeFrame++;
        }
        else if (InputEngine_->IsKey(HGEK_DOWN) == Key_Down)
        {
            m_fAngle = M_PI / 4.0f;
            m_Direction = Direction_RightDown;
            m_nPosX += m_nSpeed;
            m_nPosY += m_nSpeed;
            m_nTimeFrame++;
        }
        else
        {
            m_fAngle = 0.0f;
            m_Direction = Direction_Right;
            m_nPosX += m_nSpeed;
            m_nTimeFrame++;
        }
    }
}

void SelfPeople::Update()
{
    float fDis = ElapsedTime * m_nSpeed;
    m_nPosX += int(cos(m_fAngle) * fDis);
    m_nPosY += int(sin(m_fAngle) * fDis);

    //人物行走
    ControlMove();
}

bool SelfPeople::IsVaild()
{
    return true;
}