#include "OreilleDecorator.h"

#include <iostream>
using namespace std;

OreilleDecorator::OreilleDecorator(ICreature* ic) : CapteurDecorator(ic){
    distance = 1.;
    detection = .7;
}

bool OreilleDecorator::jeTeVois(const ICreature & ic) const{
    return true;
}