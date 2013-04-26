#include "../globaldef.h"
#include "InputEngine.h"

#define INPUT_LEFT HGEK_LEFT
#define INPUT_RIGHT HGEK_RIGHT
#define INPUT_UP HGEK_UP
#define INPUT_DOWN HGEK_DOWN

template<> InputEngine* Singleton<InputEngine>::m_pInst = NULL;

InputEngine::InputEngine()
{
    m_Key = Direction_Tail;
}

InputEngine::~InputEngine()
{
}

bool InputEngine::Initialize()
{
    return true;
}

PeopleDirection InputEngine::Get() const
{
    return m_Key;
}

void InputEngine::Update(int nKey)
{
    switch (nKey)
    {
    case INPUT_UP:
        switch (m_Key)
        {
        case Direction_Tail:
            m_Key = Direction_Up;
            break;
        case Direction_Left:
            m_Key = Direction_LeftUp;
            break;
        case Direction_Right:
            m_Key = Direction_RightUp;
            break;
        }
        break;
    case INPUT_DOWN:
        switch (m_Key)
        {
        case Direction_Tail:
            m_Key = Direction_Down;
            break;
        case Direction_Left:
            m_Key = Direction_LeftDown;
            break;
        case Direction_Right:
            m_Key = Direction_RightDown;
            break;
        case Direction_Down:
            m_Key = Direction_Down;
            break;
        }
        break;
    case INPUT_LEFT:
        switch (m_Key)
        {
        case Direction_Tail:
            m_Key = Direction_Left;
            break;
        case Direction_Up:
            m_Key = Direction_LeftUp;
            break;
        case Direction_Down:
            m_Key = Direction_LeftDown;
            break;
        }
        break;
    }
}