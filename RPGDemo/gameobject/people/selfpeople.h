#ifndef SELFPEOPLE_
#define SELFPEOPLE_

#include "people.h"

#define MOVEFRAMEMAX 5

class SelfPeople : public People
{
public:
    SelfPeople(int x = 0, int y = 0);
    virtual ~SelfPeople();

    virtual void Render();

    virtual void Update();

    virtual bool IsVaild();

    virtual void ControlMove();

protected:
    PeopleDirection m_Direction;
    int m_nPresentFrame;
    int m_nTimeFrame;
};

#endif