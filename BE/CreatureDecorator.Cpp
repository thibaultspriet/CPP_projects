#include "CreatureDecorator.h"

CreatureDecorator::CreatureDecorator(ICreature* ic) : ICreature(*ic){
    creature = ic;
};


// Méthodes déléguées à la créature emballée.

bool CreatureDecorator::jeTeVois(const ICreature & ic) const{
    return creature->jeTeVois(ic);
};

std::vector<double> CreatureDecorator::getVitesse(){
    return creature->getVitesse();
}

void CreatureDecorator::setVitesse(double vx, double vy){
    creature->setVitesse(vx,vy);
}

double CreatureDecorator::getCamouflage() const{
    return creature->getCamouflage();
}

double CreatureDecorator::getProbDeath() const{
    return creature->getProbDeath();
}