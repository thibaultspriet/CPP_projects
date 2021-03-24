#include "CamouflageDecorator.h"
#include <random>

const double CamouflageDecorator::CAMOUF_MIN = 0.1;
const double CamouflageDecorator::CAMOUF_MAX = 1.0;

CamouflageDecorator::CamouflageDecorator(ICreature* ic) : AccessoireDecorator(ic){
    
    std::default_random_engine re;
    std::uniform_real_distribution<double> camouf_range(CAMOUF_MIN,CAMOUF_MAX);

    camouflage = camouf_range(re);
};

ICreature* CamouflageDecorator::clone(){
    //cout << "clonage Camouflage decorator" << endl;
    CamouflageDecorator* creature_clone = new CamouflageDecorator(*this);
    creature_clone->creature = this->creature->clone();
    return creature_clone;
}

double CamouflageDecorator::getCamouflage() const {
    return camouflage;
};

void CamouflageDecorator::draw( UImg & support, Milieu& monMilieu, ICreature& creatureToDraw )
{
   creature->draw(support,monMilieu,creatureToDraw);
}