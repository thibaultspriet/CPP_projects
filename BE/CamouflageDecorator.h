#ifndef _CAMOUFLEGE_DECORATOR_
#define _CAMOUFLEGE_DECORATOR_

#include "AccessoireDecorator.h"

class CamouflageDecorator : public AccessoireDecorator{

    private:
        double camouflage;
    public:
        CamouflageDecorator(ICreature* ic);
        ~CamouflageDecorator(){};
        double getCamouflage(void) const override final;
        //bool jeTeVois(const ICreature & ic) const override final;
        //void draw( UImg & support ) override final;

};

#endif