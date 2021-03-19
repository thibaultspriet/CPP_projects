#include "CreatureDecorator.h"

CreatureDecorator::CreatureDecorator(ICreature * ic){
    creature = ic;
};

bool CreatureDecorator::jeTeVois(const ICreature & ic) const{
    return creature->jeTeVois(ic);
};

std::vector<double> CreatureDecorator::getVitesse(){
    //cout << "creature vitesse : " << creature->getVitesse().at(0) << " " << creature->getVitesse().at(1) << endl;
    return creature->getVitesse();
}

void CreatureDecorator::setVitesse(double vx, double vy){
    //cout << "set vitesse creature decorator";
    creature->setVitesse(vx,vy);
}

// void CreatureDecorator::draw(UImg & support){
//     creature->draw(support);
// };

double CreatureDecorator::getCamouflage() const{
    return creature->getCamouflage();
}

double CreatureDecorator::getProbDeath() const{
    return creature->getProbDeath();
}