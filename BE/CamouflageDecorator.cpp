#include "CamouflageDecorator.h"
#include <random>

const double CamouflageDecorator::CAMOUF_MIN = 0;
const double CamouflageDecorator::CAMOUF_MAX = 0;

CamouflageDecorator::CamouflageDecorator(ICreature* ic) : AccessoireDecorator(ic){
    
    std::default_random_engine re;
    std::uniform_real_distribution<double> camouf_range(CAMOUF_MIN,CAMOUF_MAX);

    camouflage = camouf_range(re);
};

double CamouflageDecorator::getCamouflage() const {
    return camouflage;
};