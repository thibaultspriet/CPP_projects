#ifndef _ACCESSOIRE_DECORATOR_
#define _ACCESSOIRE_DECORATOR_

#include "CreatureDecorator.h"
#include "ICreature.h"

class AccessoireDecorator : public CreatureDecorator{

    public:
        virtual std::vector<double> getVitesse() {return CreatureDecorator::getVitesse();} ;
        virtual void setVitesse(double vx, double vy) {CreatureDecorator::setVitesse(vx,vy);};
        AccessoireDecorator(ICreature* ic) : CreatureDecorator(ic){};
        virtual ~AccessoireDecorator(){};
        virtual bool jeTeVois(const ICreature & ic) const {return CreatureDecorator::jeTeVois(ic);} ;
        virtual double getCamouflage(void) const {return CreatureDecorator::getCamouflage();};
        virtual double getProbDeath(void) const {return CreatureDecorator::getProbDeath();};

};

#endif