#ifndef TEXTURE_
#define TEXTURE_

#include "../../hge/include/hge.h"
#include "../../hge/include/hgesprite.h"
#include <string>
#include <vector>

class Texture
{
public:
    Texture();
    virtual ~Texture();

    virtual bool Load(const std::string& strPath,
        float x, float y, float width, float height);

    virtual bool LoadFrame(const std::string& strPath,
        float y, float width, float height);

    virtual void Render(float x, float y);

    virtual void RenderFrame(int nFramePos, float x, float y);

    float GetX() const { return m_TextureX; }

    float GetY() const { return m_TextureY; }

    float GetWidth() const { return m_TextureWidth; }

    float GetHeight() const { return m_TextureHeight; }

    virtual void Release();

private:
    float m_TextureX;
    float m_TextureY;
    float m_TextureWidth;
    float m_TextureHeight;
    int m_nFrame;
    HTEXTURE m_Texture;
    hgeSprite* m_Sprite_ptr;
    std::vector<hgeSprite*> m_vecFrameSprite;
};

#endif