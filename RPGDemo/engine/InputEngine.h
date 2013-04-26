#ifndef INPUTENGINE_
#define INPUTENGINE_

#include "../unit/Singleton.h"
#include <vector>

class InputEngine : public Singleton<InputEngine>
{
    friend class Singleton<Singleton>;
public:
    InputEngine();
    virtual ~InputEngine();

    virtual bool Initialize();

    bool IsKey(int nKey);

    bool IsKey(int nFirstKey, int nSecondKey);

    void Update(int nKey);

private:
    std::vector<int> m_vecKey;
};

#endif