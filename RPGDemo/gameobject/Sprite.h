#ifndef OBJECT_
#define OBJECT_

enum _PeopleDirection
{
    Direction_Left,
    Direction_Right,
    Direction_Up,
    Direction_Down,
    Direction_Tail,
}PeopleDirection;

class ISprite
{
public:
    ISprite();
    virtual ~ISprite();

    virtual void Render() = 0;

    virtual void Update() = 0;

    virtual bool IsVaild() = 0;
};


class SpriteBase : public ISprite
{
public:
    //����λ��
    SpriteBase(int x = 0, int y = 0)
        : m_nPosX(x)
        , m_nPosY(y)
        , m_bIsVisible(true)
    {
        m_nFrameStartX      = 0;
        m_nCurrentFrame     = 0;
        m_nWidth            = 0;
        m_nHeight           = 0;
        m_nFrameCount       = 0;
    }
    virtual ~SpriteBase() {}

public:

    //����Ϊ���úͻ�ȡλ�ú���
    int GetX(){ return m_nPosX; }
    int GetY(){ return m_nPosY; }
    void SetX(int x){ m_nPosX = x; }
    void SetY(int y){ m_nPosY = y; }

protected:
    int     m_nPosX;
    int     m_nPosY;
    int     m_nFrameStartX;     //ͼƬ��ʼ��ͼ��X����
    int     m_nCurrentFrame;    //��ǰ֡
    int     m_nSpeed;           //�����ٶ�
    int     m_nFrameCount;      //֡������һ���ӵ��м���ͼ��
    int     m_nWidth;
    int     m_nHeight;
    float   m_fAngle;
    bool    m_bIsVisible;
};

#endif