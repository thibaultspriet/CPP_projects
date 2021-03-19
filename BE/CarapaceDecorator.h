#ifndef _CARAPACE_DECORATOR_
#define _CARAPACE_DECORATOR_

#include "AccessoireDecorator.h"


class CarapaceDecorator : public AccessoireDecorator{
    private:
        double protection_death;
        double decrease_vitesse;
    public:
        CarapaceDecorator(ICreature* ic);
        ~CarapaceDecorator(){};
        std::vector<double> getVitesse(void) override;
        void setVitesse(double vx, double vy) override;
        double getProbDeath(void) const override;

};

#endif