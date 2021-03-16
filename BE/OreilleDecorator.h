#ifndef _OREILLE_DECORATOR_
#define _OREILLE_DECORATOR_

#include "CapteurDecorator.h"

class OreilleDecorator : public CapteurDecorator{

    private:
        double distance;
        double detection;
    public:
        OreilleDecorator(ICreature* ic);
        bool jeTeVois(const ICreature & ic) const override final;

};

#endif