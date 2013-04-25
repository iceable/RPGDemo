#ifndef SELFPEOPLE_
#define SELFPEOPLE_

#include "people.h"

class SelfPeople : public People
{
public:
    SelfPeople(int x = 0, int y = 0);
    virtual ~SelfPeople();

    virtual void Render();

    virtual void Update();

    virtual bool IsVaild();

protected:
    PeopleDirection m_Direction;
    int m_nPresentFrame;
};

#endif