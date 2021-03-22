#include "ConcreteCreatorBestiole.h"


#include "ComportementKamikaze.h"
#include "ComportementGregaire.h"
#include "ComportementPeureuse.h"
#include "ComportementPrevoyante.h"

#include "YeuxDecorator.h"
#include "OreilleDecorator.h"
#include "NageoireDecorator.h"
#include "CarapaceDecorator.h"
#include "CamouflageDecorator.h"

#include <cmath>

using namespace std;

ConcreteCreatorBestiole::ConcreteCreatorBestiole() : IFactoryNaissance()
{
    cout << "Naissance Bestiole" << endl;
}

    
ICreature* ConcreteCreatorBestiole::create(IComportement* comportement) {
    Bestiole* bestiole = new Bestiole(comportement);

    // La bestiole a une chance sur 5 d'obtenir chaque capteur et accessoire
    if(rand() % 5 > 0){
        YeuxDecorator* bestiole = new YeuxDecorator(bestiole);
        cout << "la créature posséde des yeux" << endl;
    }
    if(rand() % 5 > 0){
        OreilleDecorator* bestiole = new OreilleDecorator(bestiole);
        cout << "la créature posséde des oreilles " << endl;
    }
    if(rand() % 5 > 0){
        NageoireDecorator* bestiole = new NageoireDecorator(bestiole);
        cout << "la créature posséde des nageoires " << endl;
    }
    if(rand() % 5 > 0){
        CamouflageDecorator* bestiole = new CamouflageDecorator(bestiole);
        cout << "la créature posséde un camouflage " << endl;
    }
    if(rand() % 5 > 0){
        CarapaceDecorator* bestiole = new CarapaceDecorator(bestiole);
        cout << "la créature posséde une carapace " << endl;
    }
    return bestiole;
}
