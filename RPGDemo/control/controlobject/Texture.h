#ifndef TEXTURE_
#define TEXTURE_

#include "../../hge/include/hge.h"
#include "../../hge/include/hgesprite.h"
#include <string>

class Texture
{
public:
    Texture();
    virtual ~Texture();

    virtual bool Load(const std::string& strPath,
        float x, float y, float width, float height);

    virtual void Render(float x, float y);

    virtual void Release();

private:
    float m_TextureX;
    float m_TextureY;
    float m_TextureWidth;
    float m_TextureHeight;
    HTEXTURE m_Texture;
    hgeSprite* m_Sprite_ptr;
};

#endif