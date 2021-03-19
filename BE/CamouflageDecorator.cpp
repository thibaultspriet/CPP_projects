#include "CamouflageDecorator.h"

CamouflageDecorator::CamouflageDecorator(ICreature* ic) : AccessoireDecorator(ic){
    camouflage = 1.;
};

double CamouflageDecorator::getCamouflage() const {
    return camouflage;
};