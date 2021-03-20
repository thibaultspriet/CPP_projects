#include "ConcreteCreatorBestiole.h"

using namespace std;

ConcreteCreatorBestiole::ConcreteCreatorBestiole() : IFactoryNaissance()
{
    cout << "Naissance Bestiole" << endl;
}
    
Bestiole ConcreteCreatorBestiole::createBestiole() {
    return new Bestiole();
}