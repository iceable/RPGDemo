#include "../../globaldef.h"
#include "Texture.h"

Texture::Texture()
{
}

Texture::~Texture()
{
    if (m_Texture)
    {
        hge->Texture_Free(m_Texture);
        m_Texture = NULL;
    }
    if (m_Sprite_ptr)
    {
        delete m_Sprite_ptr;
        m_Sprite_ptr = NULL;
    }
}

bool Texture::Load(const std::string& strPath,
        float x, float y, float width, float height)
{
    //暂时这样，完成POOL之后再进行替换
    m_Texture = hge->Texture_Load(strPath.c_str());
    if (!m_Texture)
    {
        return false;
    }
    m_Sprite_ptr = new hgeSprite(m_Texture, x, y, width, height);
    if (!m_Sprite_ptr)
    {
        return false;
    }
    return true;
}

void Texture::Render(float x, float y)
{
    m_Sprite_ptr->Render(x, y);
}

void Texture::Release()
{
    if (m_Texture)
    {
        hge->Texture_Free(m_Texture);
        m_Texture = NULL;
    }
    if (m_Sprite_ptr)
    {
        delete m_Sprite_ptr;
        m_Sprite_ptr = NULL;
    }
}