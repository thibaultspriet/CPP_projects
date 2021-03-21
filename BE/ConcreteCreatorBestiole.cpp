#include "ConcreteCreatorBestiole.h"

using namespace std;

ConcreteCreatorBestiole::ConcreteCreatorBestiole() : IFactoryNaissance()
{
    cout << "Naissance Bestiole" << endl;
}

ComportType ConcreteCreatorBestiole::getComportementNaissance(ComportType comport) const{
    return comport;
}
    
Bestiole ConcreteCreatorBestiole::create() {
    return new Bestiole();
}

Bestiole ConcreteCreatorBestiole::create(ComportType comport) {
    return new Bestiole(comport);
}