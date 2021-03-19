#ifndef _CREATURE_DECORATOR_
#define _CREATURE_DECORATOR_

#include "ICreature.h"

class CreatureDecorator : public ICreature{

    private:
        ICreature * creature;

    public:
        virtual ~CreatureDecorator() {};
        CreatureDecorator(ICreature* ic);

        bool jeTeVois(const ICreature & ic) const;
        std::vector<double> getVitesse();
        void setVitesse(double vx, double vy);
        double getCamouflage(void) const;
        double getProbDeath(void) const;

        // void draw(UImg & support);

};

#endif