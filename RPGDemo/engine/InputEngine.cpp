#include "InputEngine.h"

template<> InputEngine* Singleton<InputEngine>::m_pInst = NULL;

InputEngine::InputEngine()
{
}

InputEngine::~InputEngine()
{
}

bool InputEngine::Initialize()
{
    return true;
}

bool InputEngine::IsKey(int nKey)
{
    if (m_vecKey.empty())
    {
        return false;
    }
    if (m_vecKey.back() == nKey)
    {
        m_vecKey.pop_back();
        return true;
    }
    return false;
}

bool InputEngine::IsKey(int nFirstKey, int nSecondKey)
{
    if (m_vecKey.size() < 2)
    {
        return false;
    }
    if (m_vecKey.back() == nFirstKey)
    {
        m_vecKey.pop_back();
        if (m_vecKey.back() == nSecondKey)
        {
            m_vecKey.pop_back();
            return true;
        }
        return false;
    }
    return false;
}

void InputEngine::Update(int nKey)
{
    m_vecKey.push_back(nKey);
}