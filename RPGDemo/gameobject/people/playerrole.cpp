#include "../../globaldef.h"
#include "playerrole.h"

PlayerRole::PlayerRole(float x, float y)
    : People(x, y)
    , m_Direction(Direction_Up)
{
    LoadPeopleImage("res\\img\\self.png", 8, 128, 128);
    m_nSpeed = 3;
    m_nPresentFrame = 0;
    m_nTimeFrame = 0;
}

PlayerRole::~PlayerRole()
{
}

void PlayerRole::Render()
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
        m_nPresentFrame,(float)m_nPosX - m_nWidth/2, (float)m_nPosY - m_nHeight/2); /// 绘制在左上角 坐标表示中心
}


void PlayerRole::Update()
{
    float fDis = ElapsedTime * m_nSpeed;
    m_nPosX += int(cos(m_fAngle) * fDis);
    m_nPosY += int(sin(m_fAngle) * fDis);


    //人物行走
    //ControlMove();
    /*
    //根据运动决定下一个点位置
    if (hge->Input_GetKeyState(HGEK_UP))
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
    */
}

bool PlayerRole::IsVaild()
{
    return true;
}

roleVector PlayerRole::GetNextPos()
{
    roleVector nextPos(m_nPosX, m_nPosY);

    if (InputEngine_->IsKey(KEY_UP) == Key_Down && 
        InputEngine_->IsKey(KEY_LEFT) != Key_Down &&
        InputEngine_->IsKey(KEY_RIGHT) != Key_Down) ///向上走
    {
        m_Direction = Direction_Up;
        nextPos.y = m_nPosY - m_nSpeed;
    }
    if (InputEngine_->IsKey(KEY_DOWN) == Key_Down && 
        InputEngine_->IsKey(KEY_LEFT) != Key_Down &&
        InputEngine_->IsKey(KEY_RIGHT) != Key_Down) ///向下走
    {
        m_Direction = Direction_Down;
        nextPos.y = m_nPosY + m_nSpeed;
    }
    if (InputEngine_->IsKey(KEY_LEFT) == Key_Down && 
        InputEngine_->IsKey(KEY_DOWN) != Key_Down &&
        InputEngine_->IsKey(KEY_UP) != Key_Down) ///向左走
    {
        m_Direction = Direction_Left;
        nextPos.x = m_nPosX - m_nSpeed;
    }
    if (InputEngine_->IsKey(KEY_RIGHT) == Key_Down && 
        InputEngine_->IsKey(KEY_DOWN) != Key_Down &&
        InputEngine_->IsKey(KEY_UP) != Key_Down) ///向右走
    {
        m_Direction = Direction_Right;
        nextPos.x = m_nPosX + m_nSpeed;
    }
    if (InputEngine_->IsKey(KEY_UP) == Key_Down && 
        InputEngine_->IsKey(KEY_LEFT) == Key_Down) ///向左上走
    {
        m_Direction = Direction_LeftUp;
        nextPos.x = m_nPosX - 0.707f * m_nSpeed; /// cos45° = 0.707
        nextPos.y = m_nPosY - 0.707f * m_nSpeed;
    }
    if (InputEngine_->IsKey(KEY_UP) == Key_Down && 
        InputEngine_->IsKey(KEY_RIGHT) == Key_Down) ///向右上走
    {
        m_Direction = Direction_RightUp;
        nextPos.x = m_nPosX + 0.707f * m_nSpeed; /// cos45° = 0.707
        nextPos.y = m_nPosY - 0.707f * m_nSpeed;
    }
    if (InputEngine_->IsKey(KEY_DOWN) == Key_Down && 
        InputEngine_->IsKey(KEY_LEFT) == Key_Down) ///向左下走
    {
        m_Direction = Direction_LeftDown;
        nextPos.x = m_nPosX - 0.707f * m_nSpeed; /// cos45° = 0.707
        nextPos.y = m_nPosY + 0.707f * m_nSpeed;
    }
    if (InputEngine_->IsKey(KEY_DOWN) == Key_Down && 
        InputEngine_->IsKey(KEY_RIGHT) == Key_Down) ///向右下走
    {
        m_Direction = Direction_RightDown;
        nextPos.x = m_nPosX + 0.707f * m_nSpeed; /// cos45° = 0.707
        nextPos.y = m_nPosY + 0.707f * m_nSpeed;
    }
    return nextPos;
}

void PlayerRole::MoveTo(roleVector v)
{
    m_nPosX = v.x;
    m_nPosY = v.y;
    ++ m_nTimeFrame;
}