#ifndef _CONCRETE_H_
#define _CONCRETE_H_

#include "IFactoryNaissance.h"

class ConcreteCreatorBestiole : public IFactoryNaissance
{
    int nombreNaissance
public:
    ConcreteCreatorBesitole();
    ComportType getComportementNaissance() {};
    Bestiole create() {};
    Bestiole create(ComportType comport) {};

};

#endif