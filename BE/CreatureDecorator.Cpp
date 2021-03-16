#include "CreatureDecorator.h"

CreatureDecorator::CreatureDecorator(ICreature * ic){
    creature = ic;
};

bool CreatureDecorator::jeTeVois(const ICreature & ic) const{
    return creature->jeTeVois(ic);
};

void CreatureDecorator::draw(UImg & support){
    creature->draw(support);
};