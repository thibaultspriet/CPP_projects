#ifndef _CONCRETE_H_
#define _CONCRETE_H_

#include "IFactoryNaissance.h"

class ConcreteCreatorBestiole : public IFactoryNaissance
{
    int nombreNaissance
public:
    ConcreteCreatorBesitole();
    IComportement* getComportementNaissance() {};
    CapteurDecorator getCapteurNaissance() {};
    AccessoireDecorator getAccessoireNaissance() {};
    Bestiole createBestiole(IComportement* comportement, CapteurDecorator capteur, AccessoireDecorator accessoire) {};

};

#endif