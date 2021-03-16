#ifndef _YEUX_DECORATOR_
#define _YEUX_DECORATOR_

#include "CapteurDecorator.h"

class YeuxDecorator : public CapteurDecorator{

    private:
        double champVision;
        double distance;
        double detection;
    public:
        YeuxDecorator(ICreature* ic);
        bool jeTeVois(const ICreature & ic) const override final;
        void draw( UImg & support ) override final;

};

#endif