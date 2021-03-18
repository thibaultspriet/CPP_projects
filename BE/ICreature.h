#ifndef _I_CREATURE_H_
#define _I_CREATURE_H_
#include "Bestiole.h"


class ICreature
{
public:
    ICreature() {};
    virtual bool jeTeVois(Bestiole & b) {};
    virtual float getVitesse() {};
    virtual float getCamouflage() {};
    virtual float getProtection() {};
    virtual ICreature clone() {};

};
#endif