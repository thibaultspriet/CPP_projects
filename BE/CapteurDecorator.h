#ifndef _CAPTEUR_DECORATOR_
#define _CAPTEUR_DECORATOR_

#include "CreatureDecorator.h"
#include "ICreature.h"

class CapteurDecorator : public CreatureDecorator{

    public:
        virtual bool jeTeVois(const ICreature & ic) const = 0;
        CapteurDecorator(ICreature* ic) : CreatureDecorator(ic){};

};

#endif