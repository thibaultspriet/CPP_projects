#ifndef _CREATURE_DECORATOR_
#define _CREATURE_DECORATOR_

#include "ICreature.h"

class CreatureDecorator : public ICreature{

    private:
        ICreature * creature;

    public:
        ~CreatureDecorator() {};
        CreatureDecorator(ICreature* ic);
        bool jeTeVois(const ICreature & ic) const;
        void draw(UImg & support);

};

#endif