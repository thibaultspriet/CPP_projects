#include "ConcreteCreatorBestiole.h"

using namespace std;

ConcreteCreatorBestiole::ConcreteCreatorBestiole() : IFactoryNaissance()
{
    cout << "Naissance Bestiole" << endl;
}

IComportement* ConcreteCreatorBestiole::getComportementNaissance() {
    for (int i = 0; i < nombreNaissance; i++) {
        int choix = std::rand() % 5;
        switch (choix)
        {
        case 0:
            return ComportementPrevoyante();

        case 1:
            return ComportementPeureuse();

        case 2:
            return ComportementKamikaze();

        case 3:
            return ComportementGregaire();

        case 4:
        default:
            return ComportementMultiple();
        }
    }

    CapteurDecorator ConcreteCreatorBesitole::getCapteurNaissance() {
        return
    }

    AccessoireDecorator ConcreteCreatorBestiole::getAccessoireNaissance() {
        return
    }

    Bestiole ConcreteCreatorBestiole::createBestiole(IComportement * comportement, CapteurDecorator capteur, AccessoireDecorator accessoire) {
        return new Bestiole(this->getComportement, this->getCapteur(), this->getAccessoire())
    }