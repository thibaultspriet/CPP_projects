#ifndef _NAGEOIRE_DECORATOR_
#define _NAGEOIRE_DECORATOR_

#include "AccessoireDecorator.h"

class NageoireDecorator : public AccessoireDecorator{

    private:
        double multiple_vitesse;
    public:
        NageoireDecorator(ICreature* ic);
        ~NageoireDecorator(){};
        std::vector<double>  getVitesse() override;
        void setVitesse(double vx, double vy) override;
        //bool jeTeVois(const ICreature & ic) const override final;

};

#endif