#ifndef _I_FACTO_H_
#define _I_FACTO_H_
#include "ICreature.h"


class IFactoryNaissance
{
public:
    IFactoryNaissance() {};
    virtual ComportType getComportementNaissance() {};
    virtual ICreature create() {};
    virtual ICreature create() {};
};
#endif